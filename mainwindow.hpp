#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    /*!
     * \brief MainWindow::on_lineEditInputHEXData_textChanged функция для приведения к
     * верхнему регистру всех вводимых символов в поле lineEditInputHEXData.
     * \param arg1 исходная строка до преобразования
     */
    void on_lineEditInputHEXData_textChanged(const QString &arg1);

    void on_calculatePushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP
