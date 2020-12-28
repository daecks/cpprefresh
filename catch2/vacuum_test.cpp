#define CATCH_CONFIG_MAIN // provide a main method for tests

#include "catch_amalgamated.hpp"

bool vacuum(std::string directions);

TEST_CASE("Up and down cancel each other", "[Vertical]") {
    REQUIRE( vacuum("UD") == 1 );
}

TEST_CASE("Left and right cancel each other", "[Horizontal]") {
    REQUIRE( vacuum("LR") == 1 );
}

TEST_CASE("More left than right doesn't return to start", "[Horizontal]") {
    REQUIRE( vacuum("LLR") == 1 );
}

TEST_CASE("Move in each direction back to start", "[Horizontal][Vertical]" ) {
    REQUIRE( vacuum("LURD") == 1 );
}
