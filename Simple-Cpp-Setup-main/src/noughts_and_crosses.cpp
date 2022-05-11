#include "noughts_and_crosses.hpp"
#include <p6/p6.h>

void play_noughts_and_crosses(){
    auto      ctx      = p6::Context{};     // Create a context with a window

    /*ctx.update = [&]() {
        ctx.background({0.2f, 0.1f, 0.3f}); // Comment out this line for an interesting effect
        ctx.circle(p6::Center{ctx.mouse()}, p6::Radius{0.3f});
    };*/
    
    ctx.update = [&]() {
        ctx.background({});
        ctx.stroke = {1, 1, 1, 1};
        /*ctx.square(p6::Center{0.1f},
                   p6::Radius{0.3f},
                   p6::Rotation{0.011_turn});
        ctx.square(p6::TopLeftCorner{0.1f},
                   p6::Radius{0.3f},
                   p6::Rotation{rotation});*/
        ctx.line(glm::vec2{0.f}, glm::vec2{1.f});
    };
    ctx.start();                            //start p6 application
}
