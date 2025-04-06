add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", {outputdir = ".vscode"})

-- target("null_pointer")
--     set_kind("binary")
--     add_files("src/null_pointer.cpp")

target("dangling_pointer")
    set_kind("binary")
    add_files("src/dangling_pointer.cpp")