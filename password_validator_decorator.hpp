#pragma once
#include"password_validator.hpp"
#include<memory>

namespace kmj{

class password_validator_decorator : public password_validator{
public:
    explicit password_validator_decorator(std::unique_ptr<password_validator> validator) : inner(std::move(validator)){}
    virtual bool validator(std::string_view password) override{
        return inner->validator(password);
    }
protected:
private:
    std::unique_ptr<password_validator> inner;
};


}