#pragma once
/*
 *      Copyright (C) 2005-2010 Team XBMC
 *      http://www.xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#include "GUIControl.h"
#include "addons/IAddon.h"

class CGUIRenderingControl : public CGUIControl
{
public:
  CGUIRenderingControl(int parentID, int controlID, float posX, float posY, float width, float height);
  CGUIRenderingControl(const CGUIRenderingControl &from);
  virtual CGUIRenderingControl *Clone() const { return new CGUIRenderingControl(*this); }; //TODO check for naughties

  virtual void Render();
  virtual void UpdateVisibility(const CGUIListItem *item = NULL);
  virtual void FreeResources(bool immediately = false);
  virtual bool CanFocus() const { return false; }
  virtual bool CanFocusFromPoint(const CPoint &point) const;
  void LoadAddon(const ADDON::AddonPtr &addon);

protected:
  CCriticalSection m_rendering;
  ADDON::VizPtr m_addon;
};
