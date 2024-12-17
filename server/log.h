#pragma once
#include <string>

/** @file
 * @author Шурманов И.С.
 * @version 1.0
 * @date 17.12.2024
 * @brief Заголовочный файл для установки журнала лога
 */

/** @brief Класс для журнала лога
 */
class logger {
private:
    std::string path_to_logfile; ///< Путь к файлу лога
    bool log_to_console; ///< Флаг для вывода в консоль

public:
    logger(); ///< Конструктор по умолчанию

    logger(const std::string& path, bool log_to_console = false); ///< Конструктор с параметром

    /**
     * @brief Установка пути к файлу лога
     * 
     * Устанавливает путь к файлу лога.
     * @param [in] path_file Путь к файлу лога.
     * @param [in] log_to_console Флаг для вывода в консоль.
     * @throw crit_err Если файл не открывается.
     */
    int set_path(const std::string& path_file, bool log_to_console = false);

    /**
     * @brief Запись события в журнал
     * 
     * Записывает событие в лог.
     * @param [in] message Сообщение для записи.
     * @throw crit_err Если файл не открывается на запись.
     */
    int writelog(const std::string& message);

    /**
     * @brief Получение текущего времени
     * 
     * Позволяет получить время вместе с датой.
     * @return Строка с текущим временем.
     */
    std::string gettime();

    /**
     * @brief Получение пути к файлу лога (для модульного тестирования)
     * 
     * @return Путь к файлу лога.
     */
    std::string get_path() const;
};
