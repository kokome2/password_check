#pragma once
#include"password_validator_decorator.hpp"

namespace kmj{

class digit_password_validator final : public password_validator_decorator{
public:
    explicit digit_password_validator(std::unique_ptr<password_validator> validator) : password_validator_decorator(std::move(validator)){}
    virtual bool validator(std::string_view password) override{
        if(!password_validator_decorator::validator(password)){
            return false;
        }
        return password.find_first_of("0123456789") != std::string::npos;
    }

protected:
private:
};
} // namespace kmj

