#include <unistd.h>
#include <iostream>
#include <string>

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main(int argc, char** argv)
{
    // need to show containers which have label equal "fuzzerd"

    // root only
    std::string socket_path = "/run/podman/podman.sock";

    auto response = cpr::Get(cpr::Url{"http://localhost/v4.0.0/libpod/containers/json"},
        cpr::UnixSocket{socket_path}
    );

    auto json_object = json::parse(response.text);

    for (auto&& container: json_object) {
        std::cout << container["Names"][0] << std::endl;
    }
}
