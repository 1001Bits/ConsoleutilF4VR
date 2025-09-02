#pragma once

#pragma warning(push)
#include "F4SE/F4SE.h"
#include "RE/Fallout.h"

#include "F4SE/Logger.h"
#include <fmt/format.h>
#pragma warning(pop)

#define DLLEXPORT __declspec(dllexport)

namespace logger = F4SE::log;

using namespace std::literals;

#include "Version.h"
