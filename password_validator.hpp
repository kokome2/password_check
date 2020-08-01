#pragma once
#include<iostream>
#include<string_view>

namespace kmj{
    class password_validator{
    public:
        virtual bool validator(std::string_view password) = 0;
        password_validator() = default;
        virtual ~password_validator() = default;
    protected:
    private:
    };
}