-- premake5.lua
workspace "Multiplayer_Pacman"
    architecture "x64"
    startproject "Multiplayer_Pacman"

    configurations {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- include directories relative to root folder (sln directory)
IncludeDir = {}
IncludeDir["SFML"] = "vendor/SFML/include"

project "Multiplayer_Pacman"
    location "Multiplayer_Pacman"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/src",
        "%{IncludeDir.SFML}"
    }

    libdirs {
        "vendor/SFML/lib"
    }

    filter "system:windows"
        systemversion "latest"

        defines {
            "MYGAME_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "MULTIPLAYER_PACMAN_DEBUG"
        runtime "Debug"
        symbols "on"
        libdirs {
            "vendor/SFML/lib/Debug"
        }
        links { "sfml-audio-d", "sfml-graphics-d", "sfml-network-d", "sfml-system-d", "sfml-window-d" }
        postbuildcommands {
            "{COPY} %{wks.location}/vendor/SFML/bin/sfml-graphics-d-2.dll %{cfg.targetdir}",
            "{COPY} %{wks.location}/vendor/SFML/bin/sfml-window-d-2.dll %{cfg.targetdir}",
            "{COPY} %{wks.location}/vendor/SFML/bin/sfml-system-d-2.dll %{cfg.targetdir}",
            "{COPY} %{wks.location}/vendor/SFML/bin/sfml-audio-d-2.dll %{cfg.targetdir}",
            "{COPY} %{wks.location}/vendor/SFML/bin/sfml-network-d-2.dll %{cfg.targetdir}"
        }

    filter "configurations:Release"
        defines "MULTIPLAYER_PACMAN_RELEASE"
        runtime "Release"
        optimize "on"
        libdirs {
            "vendor/SFML/lib/Release"
        }
        links { "sfml-audio", "sfml-graphics", "sfml-network", "sfml-system", "sfml-window" }
        postbuildcommands {
            "{COPY} %{wks.location}/vendor/SFML/bin/sfml-graphics-2.dll %{cfg.targetdir}",
            "{COPY} %{wks.location}/vendor/SFML/bin/sfml-window-2.dll %{cfg.targetdir}",
            "{COPY} %{wks.location}/vendor/SFML/bin/sfml-system-2.dll %{cfg.targetdir}",
            "{COPY} %{wks.location}/vendor/SFML/bin/sfml-audio-2.dll %{cfg.targetdir}",
            "{COPY} %{wks.location}/vendor/SFML/bin/sfml-network-2.dll %{cfg.targetdir}"
        }
