#pragma once

#include <imgui.h>
#include <string>
#include <imgui-forms/field_traits.hpp>
#include <imgui-forms/field_traits_macros.hpp>
#include <iostream>
struct ExampleTraitsModel
{
    std::string name;
    std::string email;
};

template <>
struct imgui_forms::FormFieldTraits<ExampleTraitsModel>
{
    static std::string get(const ExampleTraitsModel &u, const std::string &field)
    {
        if (field == "name")
        {
            std::cout << "get name: " << u.name << std::endl;
            return u.name;
        }
        if (field == "email")
        {
            std::cout << "get email: " << u.email << std::endl;
            return u.email;
        }
        throw std::runtime_error("Unknown field: " + field);
    }

    static void set(ExampleTraitsModel &u, const std::string &field, const std::string &val)
    {
        if (field == "name")
        {
            std::cout << "set name: " << val << std::endl;
            u.name = val;
            return;
        }
        if (field == "email")
        {
            std::cout << "set email: " << val << std::endl;
            u.email = val;
            return;
        }
        throw std::runtime_error("Unknown field: " + field);
    }
};
