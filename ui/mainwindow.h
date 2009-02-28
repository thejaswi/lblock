#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "textureswindow.h"

#include <QDomDocument>
#include <QMainWindow>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow {
	Q_OBJECT

	Ui::MainWindow *ui;

	TexturesWindow texturesWindow;

	/// This is true if the file has been modified
	bool dirty;

	/// This Stores the Current filename
	QString filename;

	/// This function clears everything (except filename)
	void clear();

	/// This stores the document currently being read
	QDomDocument doc;

    public:
	MainWindow (QWidget *parent = NULL);

	~MainWindow();

    signals:
	void error(QString);

    public slots:

	void slotNew();

	void slotOpen();

	void slotSave();

	void slotSaveAs();

	void slotAbout();

	void slotAboutQt();

	void slotMakeDirty();

	void slotMakeClean();

	void slotErrorHandler(QString);
};

#endif
