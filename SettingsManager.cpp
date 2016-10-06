//
// Created by ukzz on 10/7/16.
//

#include "SettingsManager.h"

SettingsManager::SettingsManager(const std::string& filename/* = ""*/)
        : m_filename(""), m_autosave(false)
{
    if (!filename.empty())
        load(filename);
}

SettingsManager::~SettingsManager()
{
    if(m_autosave)
        save(m_filename);
}

void SettingsManager::setAutoSave(bool state)
{
    m_autosave = state;
}

bool SettingsManager::load(const std::string& filename)
{
    try {
        boost::property_tree::ini_parser::read_ini(filename, m_ptree);
        m_filename = filename;
        return true;
    } catch (std::exception &e) {
        printf("[SettingsManager->load]: %s\n", e.what());
        return false;
    }
}

bool SettingsManager::save(const std::string& filename/* = ""*/)
{
    try {
        boost::property_tree::ini_parser::write_ini(filename.empty() ? m_filename : filename, m_ptree);
        return true;
    } catch (std::exception &e) {
        printf("[SettingsManager->save]: %s\n", e.what());
        return false;
    }
}

std::string SettingsManager::path_transform(const std::vector<std::string>& value)
{
    std::string value_path("");
    for(auto& it :  value)
        value_path += it + (std::distance(&value[0], &it) != value.size()-1 ? "." : "");

    return value_path;
}
