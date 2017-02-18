// stdafx.h: Includedatei f�r Standardsystem-Includedateien
// oder h�ufig verwendete projektspezifische Includedateien,
// die nur in unregelm��igen Abst�nden ge�ndert werden.
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

// SFML
#include <SFML/Graphics.hpp>

// STL
#include <cstdint>
#include <bitset>
#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>

// TGUI
#include <TGUI/TGUI.hpp>

// own
// ResourceManager
#include "ResourceManager\ResourceManager.hpp"

// Menu
#include "Menu\Menu_Main.hpp"

// Map
#include "Map\CMapPoint.hpp"
#include "Map\CAwesomeChunk.hpp"
#include "Map\CMapPlayerInfo.hpp"
#include "Map\CMapInfo.hpp"
#include "Map\CAwesomeChunkContainer.hpp"
#include "Map\CMap.hpp"