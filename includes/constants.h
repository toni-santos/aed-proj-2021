#ifndef AED_PROJ_2021_CONSTANTS_H
#define AED_PROJ_2021_CONSTANTS_H

#include <ostream>

// Files
/**
 * @brief Where to store info about the clients.
 */
const std::string CLIENT_FILE_PATH = "../input/client.tsv";
/**
 * @brief Where to store info about the planes.
 */
const std::string PLANE_FILE_PATH = "../input/plane.tsv";
/**
 * @brief Where to store info about the airports.
 */
const std::string AIRPORT_FILE_PATH = "../input/airport.tsv";

// Terminal escape sequences
#ifdef NO_ANSI

const struct ClearScreen {
    friend std::ostream &operator<<(std::ostream &out, const ClearScreen &c) {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        return out;
    }
} CLEAR_SCREEN;

const std::string RED_TEXT = "";
const std::string GREEN_TEXT = "";
const std::string CONCEAL_TEXT = "";
const std::string STRIKE_THROUGH = "";
const std::string DISABLE_CURSOR = "";
const std::string ENABLE_CURSOR = "";
const std::string RESET_FORMATTING = "";
#else
/**
 * @brief Clears the screen.
 *
 * @note May be implemented as an escape sequence or as a system call.
 */
const std::string CLEAR_SCREEN = "\33[2J\33[H";
/**
 * @brief Turns any text that follows red.
 *
 * @note May be disabled.
 */
const std::string RED_TEXT = "\33[31m";
/**
 * @brief Turns any text that follows green.
 *
 * @note May be disabled.
 */
const std::string GREEN_TEXT = "\33[32m";
/**
 * @brief Hides any text that follows.
 *
 * @note May be disabled.
 */
const std::string CONCEAL_TEXT = "\33[8m";
/**
 * @brief Crosses out any text that follows.
 *
 * @note May be disabled.
 */
const std::string STRIKE_THROUGH = "\33[9m";
/**
 * @brief Disables the terminal cursor.
 *
 * @note May be disabled.
 */
const std::string DISABLE_CURSOR = "\33[?25l";
/**
 * @brief Enables the terminal cursor.
 *
 * @note May be disabled.
 */
const std::string ENABLE_CURSOR = "\33[?25h";
/**
 * @brief Resets any text that follows back to normal.
 *
 * @note May be disabled.
 */
const std::string RESET_FORMATTING = "\33[0m";
#endif // NO_ANSI

// Others
/**
 * @brief The name of the airline company, shown at the top of each menu.
 */
const std::string COMPANY_NAME =
    STRIKE_THROUGH + "[REDACTED]" + RESET_FORMATTING + " AIRLINES";

#endif // AED_PROJ_2021_CONSTANTS_H
