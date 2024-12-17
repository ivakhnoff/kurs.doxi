#pragma once
#include <map>
#include <string>

/** @file
 * @author Шурманов И.С.
 * @version 1.0
 * @date 17.12.2024
 * @brief Заголовочный файл для модуля базы данных
 */

/** @brief Класс для чтения базы данных
 * @details Контейнер data_base хранит в себе логин и пароль пользователя.
 * Для получения базы используется метод get_data().
 */
class base
{
private:
    std::map<std::string, std::string> data_base; ///< Контейнер "логин+пароль"

public:
    /**
     * @brief Установка соединения с базой данных
     * 
     * Читает из файла строку базы данных.
     * 
     * @param [in] f Путь к файлу базы данных.
     * @throw crit_err Если файл не открывается, либо несоответствие формату строки "логин:пароль".
     */
    void connect(std::string f);

    /**
     * @brief Получить базу данных
     * @return Контейнер с базой данных.
     */
    std::map<std::string, std::string> get_data()
    {
        return data_base;
    }

    /**
     * @brief Проверка наличия логина в базе данных
     * @param [in] login Логин для проверки.
     * @return true, если логин существует, иначе false.
     */
    bool has_login(const std::string& login) const
    {
        return data_base.find(login) != data_base.end();
    }

    /**
     * @brief Получение пароля по логину
     * @param [in] login Логин.
     * @return Пароль, если логин существует, иначе пустая строка.
     */
    std::string get_password(const std::string& login) const
    {
        auto it = data_base.find(login);
        if (it != data_base.end()) {
            return it->second;
        }
        return "";
    }
};
