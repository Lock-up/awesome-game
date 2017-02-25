// stdafx.h: Includedatei für Standardsystem-Includedateien
// oder häufig verwendete projektspezifische Includedateien,
// die nur in unregelmäßigen Abständen geändert werden.
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

// SFML
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>

// STL
#include <algorithm>
#include <array>

#include <bitset>

#include <cstdint>
#include <cassert>

#include <fstream>

#include <iostream>

#include <list>

#include <map>
#include <memory>

#include <string>
#include <stdexcept>

#include <vector>

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

// Node
#include "Node\SceneNode.hpp"

