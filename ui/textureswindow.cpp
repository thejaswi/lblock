#include "textureswindow.h"
#include "ui_textureswindow.h"
#include "edittexture.h"

#include <QDebug>

TexturesWindow::TexturesWindow(QDomDocument *d, QWidget *parent) : QDialog(parent), model(d, this), doc(d)
{
	ui = new Ui::TexturesWindow;
	ui->setupUi(this);

	connect(ui->listView, SIGNAL(editTexture(QString)), this, SLOT(slotEditTexture(QString)));

	ui->listView->setModel(&model);
	ui->listView->setViewMode(QListView::IconMode);
	ui->listView->setMovement(QListView::Static);
	ui->listView->setAcceptDrops(true);
}

TexturesWindow::~TexturesWindow()
{
	delete ui;
}

void TexturesWindow::refresh()
{
	model.parse();
}

void TexturesWindow::slotEditTexture(QString item)
{
	EditTexture *edit = new EditTexture(item, doc, this);
	connect(edit, SIGNAL(accepted()), parent(), SLOT(slotMakeDirty()));
	edit->show();
}
