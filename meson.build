project('imgui-forms', 'cpp')


imgui_dep = dependency('imgui', fallback: ['imgui', 'imgui_dep'])
cpp_forms_dep = dependency('cpp-forms', fallback: ['cpp-forms', 'cpp_forms_dep'])

imgui_forms_dirs = include_directories('include')
imgui_forms_dep = declare_dependency(
    include_directories: imgui_forms_dirs,
    dependencies: [imgui_dep, cpp_forms_dep],
)

meson.override_dependency('imgui-forms', imgui_forms_dep)

if not meson.is_subproject()
    subdir('examples')
endif
