#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include "crc16modbus.hpp"

#include <QRegExp>
#include <QtCore/QtEndian>
#include <QShortcut>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Создаём валидатор отсеивающий весь ввод кроме шестнадцетиричного кода байтов.
    // Диапозонн ввода - это цифры от 0 до 9 и буквы латинского алфавита от A до F,
    // в верхнем и нижнем регистре.
    QRegExp HEXregExp("[A-Fa-f0-9]{0,}");

    ui->lineEditInputHEXData->setValidator(new QRegExpValidator(HEXregExp, this));

    // Для расчёта контрольой суммы по нажатию на клавишу Enter.
    connect(ui->lineEditInputHEXData, SIGNAL(returnPressed()),
            this, SLOT(on_calculatePushButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEditInputHEXData_textChanged(const QString &arg1)
{
    ui->lineEditInputHEXData->setText(arg1.toUpper());
}

void MainWindow::on_calculatePushButton_clicked()
{
    /*!
     * \brief crc16 объект расчитывающий контрольную сумму.
     * В качестве аргумента отправляем сюда в шестнацатиричном формате набор байтов,
     * при этом считаем его именно массивом байтов.
     */
    CRC16Modbus crc16(QByteArray::fromHex(ui->lineEditInputHEXData->text().toLocal8Bit()));


    /// Получаем результат расчёта как массив байтов в QByteArray.
    ui->lineEditOutputCRC->setText(crc16.CRC16Data().toHex().toUpper());
}
