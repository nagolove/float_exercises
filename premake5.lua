workspace "test"
    architecture "x64"
    configurations {
        "Debug",
        "Release"
    }

project "float_exercise"
    kind "ConsoleApp"
    targetdir(".")
    language "C++"
    files { "*.cpp" }
    links { "m", "stdc++" }
