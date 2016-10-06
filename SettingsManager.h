//
// Created by ukzz on 10/7/16.
//

#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <vector>
#include <string>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>


class SettingsManager
{
public:
    SettingsManager(const std::string& filename = "");
    ~SettingsManager();

    bool load(const std::string& filename);
    bool save(const std::string& filename = "");

    void setAutoSave(bool state);

    template<typename T>
    T read_value(const std::vector<std::string>& value)
    {
        try {
            return m_ptree.get<T>(path_transform(value));
        } catch (std::exception &e) {
            printf("[SettingsManager->read_value]: %s\n", e.what());
            return T();
        }
    }

    template<typename T>
    void save_value(const std::vector<std::string>& value, T&& data)
    {
        try {
            m_ptree.put<T>(path_transform(value), data);
            if(m_autosave) save(m_filename);
        } catch (std::exception &e) {
            printf("[SettingsManager->save_value]: %s\n", e.what());
        }
    }

protected:
    std::string path_transform(const std::vector<std::string>& value);

protected:
    std::string m_filename;
    bool m_autosave;

private:
    boost::property_tree::ptree m_ptree;
};

#endif //SETTINGSMANAGER_H
