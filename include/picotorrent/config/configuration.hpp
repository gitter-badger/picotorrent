#pragma once

#include <map>
#include <memory>
#include <string>

namespace picojson
{
    class value;
    typedef std::map<std::string, value> object;
}

namespace picotorrent
{
namespace config
{
    class configuration
    {
    public:
        configuration();
        ~configuration();

        static configuration &instance();

        int alert_queue_size();
        
        std::wstring default_save_path();
        void set_default_save_path(const std::wstring &path);

        std::wstring listen_interface();
        
        int listen_port();
        void set_listen_port(int port);

        int stop_tracker_timeout();

    private:
        template<typename T>
        T get_or_default(const char *name, T defaultValue);

        template<typename T>
        void set(const char *name, T value);

        template<>
        int get_or_default(const char *name, int defaultValue);

        template<>
        std::wstring get_or_default(const char *name, std::wstring defaultValue);

        template<>
        void set(const char *name, int value);

        template<>
        void set(const char *name, std::wstring value);

        void load();
        void save();

        std::unique_ptr<picojson::object> value_;
    };
}
}
