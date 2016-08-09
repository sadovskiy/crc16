/*!
  \file
  \brief Заголовочный файл класса по расчёту контрольной суммы.


  Тут находятся определения класса CRC16Modbus.
  */
#ifndef CRC16MODBUS_HPP
#define CRC16MODBUS_HPP

#include <QString>
#include <QByteArray>

/*!
 * \brief The CRC16Modbus класс предназначен для расчёта
 * контрольной суммы CRC 16 Modbus.
 * \author Садовский Борис Сергеевич.
 * \version 1.0
 * \date Август 2016 года
 *
 *
 * Класс принимая через конструктор или/и метод setCRC16() байты
 * производит для них подсчёт контрольной суммы.
 */
class CRC16Modbus
{
    enum {arrayCRCTableLength = 256};

    QByteArray result;
    quint16 crcTable[arrayCRCTableLength]; //< test

    /*!
     * \brief CRC16Modbus::initCRC16Table метод создаёт таблицу CRC-16.
     */
    void initCRC16Table();

    /*!
     * \brief CRC16Modbus::calculateCRC16 расчёт контрольной суммы.
     * Результат записывается во внутренний массив, который можно получить
     * вызвав метод CRC16Data().
     * \param src исходные байты для расчёта.
     */
    void calculateCRC16(const QByteArray src = 0);
    quint16 updateCRC16(quint16 crc, const quint8 c);

public:
    /*!
     * @brief CRC16ModBus Конструктор рассчитывает из полученного массива байтов
     * контрольную сумму CRC-16.
     */
    CRC16Modbus(const QByteArray src = 0);

    /*!
     * \brief CRC16Modbus::CRC16Table выводит таблицу в консоль, если включён режим отладки.
     * Возвращает таблицу как массив строк QString.
     * \return Таблица как набор строк.
     */
    QStringList CRC16Table() const;

    /*!
     * \brief CRC16Modbus::CRC16Data метод выдаёт результат вычислений контрольной суммы.
     * \return возвращаем результат как массив байт QByteArray.
     */
    QByteArray CRC16Data() const;

    /*!
     * \brief CRC16Modbus::setCRC16 метод записывает и пересчитывает новые данные если
     * объект уже создан.
     * \param src новый массив с данными.
     */
    void setCRC16(const QByteArray src = 0);
};

#endif // CRC16MODBUS_HPP
