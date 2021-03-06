/*
 *	Copyright (C) 2007-2009 Gabest
 *	http://www.gabest.org
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
 *  along with GNU Make; see the file COPYING.  If not, write to
 *  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#pragma once

#include "GSDialog.h"
#include "GSSetting.h"

class GSShaderDlg : public GSDialog
{
	int m_saturation;
	int m_brightness;
	int m_contrast;

	void UpdateControls();

protected:
	void OnInit();
	bool OnMessage(UINT message, WPARAM wParam, LPARAM lParam);	

public:
	GSShaderDlg();
};

class GSHacksDlg : public GSDialog
{
	unsigned short cb2msaa[17];
	unsigned short msaa2cb[17];
	std::string adapter_id;
	
	bool isdx9;

	void UpdateControls();

protected:
	void OnInit();
	bool OnMessage(UINT message, WPARAM wParam, LPARAM lParam);

public:
	GSHacksDlg();

	// Ugh
	void SetAdapter(std::string adapter_id_)
	{
		adapter_id = adapter_id_;
	}
};

class GSOSDDlg : public GSDialog
{
	int m_transparency;

	void UpdateControls();

protected:
	void OnInit();
	bool OnMessage(UINT message, WPARAM wParam, LPARAM lParam);

public:
	GSOSDDlg();
};

class GSSettingsDlg : public GSDialog
{

	struct Adapter
	{
		std::string name;
		std::string id;
		D3D_FEATURE_LEVEL level;
		Adapter(const std::string &n, const std::string &i, const D3D_FEATURE_LEVEL &l) : name(n), id(i), level(l) {}
	};
	
	std::vector<Adapter> adapters;

	vector<GSSetting> m_ocl_devs;
	uint32 m_lastValidMsaa; // used to revert to previous dialog value if the user changed to invalid one, or lesser one and canceled

	void UpdateRenderers();
	void UpdateControls();
	void UpdateFilteringCombobox();

protected:
	void OnInit();
	bool OnCommand(HWND hWnd, UINT id, UINT code);

	// Shade Boost
	GSShaderDlg ShaderDlg;
	GSHacksDlg HacksDlg;
	GSOSDDlg OSDDlg;

public:
	GSSettingsDlg();
};
