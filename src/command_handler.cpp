#include "include/command_handler.h"

CommandHandler::CommandHandler(dpp::cluster& bot) : bot(bot) {}

void CommandHandler::handle(const dpp::slashcommand_t& event) {
    const std::string& command = event.command.get_command_name();

    if (command == "balance" || command == "coins") {
        handle_balance(event);
    } else if (command == "dice") {
        handle_dice(event);
    } else if (command == "rps") {
        handle_rps(event);
    } else if (command == "roulette") {
        handle_roulette(event);
    } else if (command == "guess") {
        handle_guess(event);
    } else if (command == "market" || command == "shop") {
        handle_market(event);
    } else if (command == "buy") {
        handle_buy(event);
    } else if (command == "richest" || command == "top") {
        handle_richest(event);
    } else if (command == "work") {
        handle_work(event);
    } else if (command == "daily") {
        handle_daily(event);
    } else {
        event.reply("Unknown command.");
    }
}

// TODO: Implement w/ coroutines
void CommandHandler::handle_balance(const dpp::slashcommand_t& event) {
    event.reply("Balance command not implemented yet.");
}

void CommandHandler::handle_dice(const dpp::slashcommand_t& event) {
    int amount = event.get_parameter("amount");
    std::optional<dpp::snowflake> user_id = event.get_parameter<dpp::snowflake>("user");

    if (user_id) {
        event.reply("You challenged <@" + std::to_string(*user_id) + "> to roll a dice for " + std::to_string(amount) + " coins!");
    } else {
        event.reply("You rolled the dice for " + std::to_string(amount) + " coins!");
    }
}

void CommandHandler::handle_rps(const dpp::slashcommand_t& event) {
    event.reply("Rock, Paper, Scissors command not implemented yet");
}

void CommandHandler::handle_roulette(const dpp::slashcommand_t& event) {
    event.reply("Roulette command not implemented yet");
}

void CommandHandler::handle_guess(const dpp::slashcommand_t& event) {
    event.reply("Guess command not implemented yet");
}

void CommandHandler::handle_market(const dpp::slashcommand_t& event) {
    event.reply("Market/Shop command not implemented yet");
}

void CommandHandler::handle_buy(const dpp::slashcommand_t& event) {
    event.reply("Buy command not implemented yet");
}

void CommandHandler::handle_richest(const dpp::slashcommand_t& event) {
    event.reply("Richest/Top command not implemented yet");
}

void CommandHandler::handle_work(const dpp::slashcommand_t& event) {
    std::string job = event.get_parameter("job");

    if (job == "construction_work") {
        event.reply("You worked in construction, you feel tired but made XYZ");
    } else if (job == "office_job") {
        event.reply("You worked an office job, its not difficult and you made XYZ");
    } else if (job == "startup_founder") {
        event.reply("You took a risky gamble as a startup founder and earnt nothing!");
    } else {
        event.reply("Invalid job --- You wasted your time!");
    }
}

void CommandHandler::handle_daily(const dpp::slashcommand_t& event) {
    event.reply("Daily reward not implemented yet");
}
