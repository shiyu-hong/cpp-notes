add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", {outputdir = ".vscode"})

-- target("local_variable")
--     set_kind("binary")
--     add_files("src/local_variable.cpp")

-- target("condition")
--     set_kind("binary")
--     add_files("src/condition.cpp")

-- target("array")
--     set_kind("binary")
--     add_files("src/array.cpp")

-- target("class")
--     set_kind("binary")
--     add_files("src/class.cpp")

target("pointer")
    set_kind("binary")
    add_files("src/pointer.cpp")