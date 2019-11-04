workspace "test"
    architecture "x64"
    configurations {
        "Debug",
        "Release"
    }

project "float_exercise"
    kind "ConsoleApp"
    language "C++"
    files { "*.cpp" }
    links { "m", "stdc++" }
