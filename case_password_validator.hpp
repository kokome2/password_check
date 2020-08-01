#pragma once
#include"password_validator_decorator.hpp"

namespace kmj{
class case_password_validator : public password_validator_decorator{
public:
    explicit case_password_validator(std::unique_ptr<password_validator> validator) : password_validator_decorator(std::move(validator)){}
    virtual bool validator(std::string_view password) override{
        if(!password_validator_decorator::validator(password)){
            return false;
        }
        bool haslower = false;
        bool hasupper = false;

        for(size_t i = 0; password.length() && !(hasupper && haslower) ; ++i){
            if(islower(password[i])){
                haslower = true;
            }else if(isupper(password[i])){
                hasupper = true;
            }
        }
        return haslower && hasupper;
    }        
protected:
private:
};
}