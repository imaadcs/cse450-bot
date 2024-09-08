#include <dpp/dpp.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <optional>
#include "include/command_register.h"
#include "include/CommandHandler.h"

std::optional<std::string> parse_args(int argc, char* argv[]);
void display_help();

const std::string BOT_TOKEN = std::getenv("CSE450BOTTOKEN");

int main(int argc, char* argv[]) {
    auto operation = parse_args(argc, argv);
    if (!operation) {
        return 1;
    }

    dpp::cluster bot(BOT_TOKEN);
    bot.on_log(dpp::utility::cout_logger());

    if (*operation == "register-on-load") {
        register_global_commands(bot);
    }

    CommandHandler command_handler(bot);

    bot.on_slashcommand([&command_handler](const dpp::slashcommand_t& event) {
        command_handler.handle(event);
    });

    bot.on_ready([&bot](const dpp::ready_t& event) {
        std::cout << "Bot is ready!\n";
    });

    bot.start(dpp::st_wait);
    return 0;
}

void display_help() {
    std::cout << R"(
Usage: bot [options]
Options:
  --help, -h              Show this help message and exit
  --register-on-load      Register global commands when the bot starts
)";
}

std::optional<std::string> parse_args(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " [options]\n";
        display_help();
        return std::nullopt;
    }

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "--help" || arg == "-h") {
            display_help();
            return std::nullopt;
        } else if (arg == "--register-on-load") {
            return "register-on-load";
        } else {
            std::cerr << "Unknown argument: " << arg << "\n";
            return std::nullopt;
        }
    }

    return std::nullopt;
}
