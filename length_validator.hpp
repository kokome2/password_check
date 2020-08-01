#pragma once
#include"password_validator.hpp"

namespace kmj{
class length_validator final : public password_validator{
public:
    length_validator(unsigned int min_length) : length(min_length){}
    virtual bool validator(std::string_view password) override{
        return password.length() >= length;
    }
protected:
private:
    unsigned int length;
};

}
