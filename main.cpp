#include "SettingsManager.h"

int main(int argc, char** argv)
{
    // Load config
    SettingsManager settings_mgr("example-settings.ini");

    // Read existig
    int nVal = settings_mgr.read_value<int>({ "foobar", "nval" });
    std::string sVal = settings_mgr.read_value<std::string>({ "foobar2", "sval" });

    // Auto-save after write
    settings_mgr.setAutoSave(true);

    // Edit existing
    settings_mgr.save_value<int>({ "foobar", "fval"}, 123.1322);

    // Create new entry if doesnt exists
    settings_mgr.save_value<int>({ "test", "a"}, 123);

    // Save loaded config
    settings_mgr.save();

    // Save at new location
    settings_mgr.save("duplicated-settings.ini");

    return 0;
}