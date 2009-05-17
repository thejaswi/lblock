#include "lblockxmlengine.h"

QDomNode LBlockXmlEngine::getCurrentFloor(int n)
{
	QDomNode floor;
	for (floor = elementsByTagName("floors").item(0).toElement().firstChild(); !floor.isNull(); floor = floor.nextSibling())
		if (floor.toElement().attribute("id") == QString::number(n))
			return floor;
}

LBlockValues elementToHash(const QDomElement &elem)
{
	LBlockValues hash(elem);

	QDomNamedNodeMap attributes = elem.attributes();
	for (int i = 0; i < attributes.length(); i++) {
		QDomAttr item = attributes.item(i).toAttr();
		hash[item.name()] = item.value();
	}

	return hash;
}

LBlockValues LBlockXmlEngine::getProperties()
{
	QDomElement elem = documentElement().toElement().elementsByTagName("properties").item(0).toElement();	
	return elementToHash(elem);
}

LBlockXmlEngine::LBlockXmlEngine(const char *name) : QDomDocument(name)
{

}

LBlockValuesList LBlockXmlEngine::getItemsOnFloor(int n)
{
	QDomNode floor = getCurrentFloor(n);

	QList <LBlockValues> values;

	for (QDomNode item = floor.toElement().elementsByTagName("item").item(0); !item.isNull(); item = item.nextSibling())
		values << elementToHash(item.toElement());

	return values;
}

void LBlockXmlEngine::addItemOnFloor(int n, const LBlockValues &hash)
{
	QDomElement floor = getCurrentFloor(n).toElement();

	QDomElement elem = createElement("item");
	QHashIterator<QString, QString> i(hash);

	while (i.hasNext()) {
		i.next();
		elem.setAttribute(i.key(), i.value());
	}

	floor.appendChild(elem);
}

LBlockValues LBlockXmlEngine::getItemOnFloor(int n, const QString &name)
{
	QDomElement floor = getCurrentFloor(n).toElement();

	QDomNode item;
	for (item = floor.elementsByTagName("item").item(0); !item.isNull(); item = item.nextSibling())
		if (item.toElement().attribute("name") == name)
			return elementToHash(item.toElement());
		
	return LBlockValues();
}