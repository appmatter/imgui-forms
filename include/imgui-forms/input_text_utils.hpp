#pragma once
#include <imgui.h>
#include <string>

namespace imgui_forms
{

    static inline int InputTextCallback(ImGuiInputTextCallbackData *data)
    {
        if (data->EventFlag == ImGuiInputTextFlags_CallbackResize)
        {
            auto *str = static_cast<std::string *>(data->UserData);
            IM_ASSERT(data->Buf == str->c_str());
            str->resize(data->BufTextLen);
            data->Buf = const_cast<char *>(str->c_str());
        }
        return 0;
    }

}
