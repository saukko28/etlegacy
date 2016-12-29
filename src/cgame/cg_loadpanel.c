/*
 * Wolfenstein: Enemy Territory GPL Source Code
 * Copyright (C) 1999-2010 id Software LLC, a ZeniMax Media company.
 *
 * ET: Legacy
 * Copyright (C) 2012-2016 ET:Legacy team <mail@etlegacy.com>
 *
 * This file is part of ET: Legacy - http://www.etlegacy.com
 *
 * ET: Legacy is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ET: Legacy is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with ET: Legacy. If not, see <http://www.gnu.org/licenses/>.
 *
 * In addition, Wolfenstein: Enemy Territory GPL Source Code is also
 * subject to certain additional terms. You should have received a copy
 * of these additional terms immediately following the terms and conditions
 * of the GNU General Public License which accompanied the source code.
 * If not, please request a copy in writing from id Software at the address below.
 *
 * id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.
 */
/**
 * @file cg_local.h
 */

#include "cg_local.h"

extern displayContextDef_t *DC;

qboolean  bg_loadscreeninited = qfalse;
qhandle_t bg_mappic;

// panel_button_text_t FONTNAME = { SCALEX, SCALEY, COLOUR, STYLE, FONT };

panel_button_text_t missiondescriptionTxt =
{
	0.2f,                          0.2f,
	{ 0.0f,                        0.0f,0.0f,    1.f },
	0,                             0,
	&cgs.media.bg_loadscreenfont2,
};

panel_button_text_t missiondescriptionHeaderTxt =
{
	0.2f,                          0.2f,
	{ 0.0f,                        0.0f,             0.0f,    0.8f },
	0,                             ITEM_ALIGN_CENTER,
	&cgs.media.bg_loadscreenfont2,
};

panel_button_text_t campaignpheaderTxt =
{
	0.2f,                          0.2f,
	{ 1.0f,                        1.0f,1.0f,    0.6f },
	0,                             0,
	&cgs.media.bg_loadscreenfont2,
};

panel_button_text_t campaignpTxt =
{
	0.22f,                         0.22f,
	{ 1.0f,                        1.0f, 1.0f,  0.6f },
	0,                             0,
	&cgs.media.bg_loadscreenfont2,
};

panel_button_text_t loadScreenMeterBackTxt =
{
	0.22f,                         0.22f,
	{ 0.1f,                        0.1f,             0.1f,  0.8f },
	0,                             ITEM_ALIGN_CENTER,
	&cgs.media.bg_loadscreenfont2,
};

panel_button_t loadScreenBack =
{
	"gfx/loading/banner_trans",
	NULL,
	{ 0,                    350,  640, 69 },
	{ 0,                      0,  0,   0, 0, 0, 0, 0},
	NULL,                     /* font     */
	NULL,                     /* keyDown  */
	NULL,                     /* keyUp    */
	BG_PanelButtonsRender_Img,
	NULL,
	0
};

panel_button_t missiondescriptionPanelText =
{
	NULL,
	NULL,
	{ 15,                                    30,   620, 232 },
	{ 0,                                      0,    0,   0, 0, 0, 0, 0},
	&missiondescriptionTxt,                   /* font     */
	NULL,                                     /* keyDown  */
	NULL,                                     /* keyUp    */
	CG_LoadPanel_RenderMissionDescriptionText,
	NULL,
	0
};

panel_button_t campaignheaderPanelText =
{
	NULL,
	NULL,
	{ 15,                              15,   152, 232 },
	{ 0,                                0,    0,   0, 0, 0, 0, 0},
	&campaignpheaderTxt,                /* font     */
	NULL,                               /* keyDown  */
	NULL,                               /* keyUp    */
	CG_LoadPanel_RenderCampaignTypeText,
	NULL,
	0
};

panel_button_t campaignPanelText =
{
	NULL,
	NULL,
	{ 15,                              30,   152, 232 },
	{ 0,                                0,    0,   0, 0, 0, 0, 0},
	&campaignpTxt,                      /* font     */
	NULL,                               /* keyDown  */
	NULL,                               /* keyUp    */
	CG_LoadPanel_RenderCampaignNameText,
	NULL,
	0
};

panel_button_t loadScreenMeterBack =
{
	"gfx/loading/progressbar_back",
	NULL,
	{ 170,                    480 - 30 + 1, 300, 15 },
	{ 0,                           0,  0,        0, 0, 0, 0, 0},
	NULL,                          /* font     */
	NULL,                          /* keyDown  */
	NULL,                          /* keyUp    */
	BG_PanelButtonsRender_Img,
	NULL,
	0
};

panel_button_t loadScreenMeterBack2 =
{
	"gfx/loading/progressbar",
	NULL,
	{ 170,                   480 - 29 + 1, 300, 13 },
	{ 1,                          255,  0,        0, 255, 0, 0, 0},
	NULL,                         /* font     */
	NULL,                         /* keyDown  */
	NULL,                         /* keyUp    */
	CG_LoadPanel_RenderLoadingBar,
	NULL,
	0
};

panel_button_t loadScreenMeterBackText =
{
	NULL,
	"LOADING",
	{ 275,                 480 - 31 + 12 + 1,   300 - 2, 12 },
	{ 0,                        0,                   0,            0, 0, 0, 0, 0},
	&loadScreenMeterBackTxt,    /* font     */
	NULL,                       /* keyDown  */
	NULL,                       /* keyUp    */
	CG_LoadPanel_LoadingBarText,
	NULL,
	0
};

panel_button_t *loadpanelButtons[] =
{
	&loadScreenBack,              &missiondescriptionPanelText,
	&campaignheaderPanelText,     &campaignPanelText,
	&loadScreenMeterBack,         &loadScreenMeterBack2,             &loadScreenMeterBackText,
	NULL,
};

/**
 * @brief CG_LoadPanel_GameTypeName
 * @param[in] gt
 * @return
 */
const char *CG_LoadPanel_GameTypeName(gametype_t gt)
{
	switch (gt)
	{
	case GT_SINGLE_PLAYER:
		return CG_TranslateString("Single Player");
	case GT_COOP:
		return CG_TranslateString("Co-op");
	case GT_WOLF:
		return CG_TranslateString("Objective");
	case GT_WOLF_STOPWATCH:
		return CG_TranslateString("Stopwatch");
	case GT_WOLF_CAMPAIGN:
		return CG_TranslateString("Campaign");
	case GT_WOLF_LMS:
		return CG_TranslateString("Last Man Standing");
	case GT_WOLF_MAPVOTE:
		return CG_TranslateString("Map Voting");
	default:
		break;
	}

	return "Invalid";
}

static vec4_t clr3 = { 1.f, 1.f, 1.f, .6f };

/**
 * @brief CG_DrawConnectScreen
 * @param[in] interactive
 * @param[in] forcerefresh
 */
void CG_DrawConnectScreen(qboolean interactive, qboolean forcerefresh)
{
	static qboolean inside = qfalse;
	char            buffer[1024];

	if (!DC)
	{
		return;
	}

	if (inside)
	{
		return;
	}

	inside = qtrue;

	if (!bg_loadscreeninited)
	{
		trap_Cvar_Set("ui_connecting", "0");

		RegisterFont("ariblk", 27, &cgs.media.bg_loadscreenfont1);
		RegisterFont("courbd", 30, &cgs.media.bg_loadscreenfont2);


		bg_mappic = 0;

		BG_PanelButtonsSetup(loadpanelButtons);
		C_PanelButtonsSetup(loadpanelButtons, cgs.wideXoffset);

		bg_loadscreeninited = qtrue;
	}



	if (*cgs.rawmapname)
	{
		float x = 0 + cgs.wideXoffset;

		if (!bg_mappic)
		{
			bg_mappic = DC->registerShaderNoMip(va("levelshots/%s", cgs.rawmapname));
			if (!bg_mappic)
			{
				bg_mappic = DC->registerShaderNoMip("levelshots/unknownmap");
			}
		}
		
		trap_R_SetColor(colorBlack);
		CG_DrawPic(x, 0, 640, 480, bg_mappic);
		
		int r_mode = (int)(DC->getCVarValue("r_mode"));

		switch (r_mode)
		{
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
				trap_R_SetColor(NULL);
				CG_DrawPic(x, 0, 640, 480, bg_mappic);
				break;
			case 10:
				// need more info on this one
				break;
			case 11:
			case 12:
			case 13:
			case 14:
				 break;
			case 15:
				trap_R_SetColor(NULL);
				CG_DrawPic(x, 0, 640, 480, bg_mappic);
				break;
			case 16:
			case 17:
				trap_R_SetColor(NULL);
				CG_DrawPic(x - cgs.wideXoffset, 0, 640 + 250, 480, bg_mappic);
				break;
			case 18:
				// need more info on this one
			case 19:
				// need more info on this one
			case 20:
				// need more info on this one
				break;
			case -2:
				// suppose majortly of people is using 1080p displays for destop resolution
				trap_R_SetColor(NULL);
				CG_DrawPic(x - cgs.wideXoffset, 0, 640 + 250, 480, bg_mappic);
				break;
			default:
				trap_R_SetColor(NULL);
				CG_DrawPic(x, 0, 640, 480, bg_mappic);
				break;
		}
		
	BG_PanelButtonsRender(loadpanelButtons);

	if (interactive)
	{
		DC->drawHandlePic(DC->cursorx, DC->cursory, 32, 32, DC->Assets.cursor);
	}

	DC->getConfigString(CS_SERVERINFO, buffer, sizeof(buffer));
	if (*buffer)
	{
		const char *str;
		float      x = 320.0f + cgs.wideXoffset;
		float      y = 360;
		int        i;
		qboolean   enabled = qfalse;

		str = Info_ValueForKey(buffer, "sv_hostname");
		CG_Text_Paint_Centred_Ext(x, y, 0.2f, 0.2f, colorWhite, str && *str ? str : "ETHost", 0, 26, 0, &cgs.media.bg_loadscreenfont2);

		y += 14;
		for (i = 0; i < MAX_MOTDLINES; i++)
		{
			str = CG_ConfigString(CS_CUSTMOTD + i);
			if (!str || !*str)
			{
				break;
			}

			CG_Text_Paint_Centred_Ext(x, y, 0.2f, 0.2f, colorWhite, str, 0, 26, 0, &cgs.media.bg_loadscreenfont2);

			y += 10;
		}

		y   = 470;

		switch (r_mode)
		{
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
				x+=245;
				break;
			case 10:
				//x+=?;
				break;
			case 11:
			case 12:
			case 13:
			case 14:
				//x+=?;
				break;
			case 15:
				x += 245;
				break;
			case 16:
			case 17:
				x += 350;
				break;
			case 18:
			case 19:
			case 20:
				break;
			case -2:
				x += 350;
				break;
			default:
				x += 245;
				break;
		}

		CG_Text_Paint_Centred_Ext(x, y, 0.22f, 0.22f, clr3, ("^1" LEGACY_MOD " ^0" ETLEGACY_VERSION), 0, 0, 0, &cgs.media.bg_loadscreenfont1);


	}
	
	}

	if (forcerefresh)
	{
		DC->updateScreen();
	}

	inside = qfalse;
}

/**
 * @brief CG_LoadPanel_RenderLoadingBar
 * @param[in] button
 */
void CG_LoadPanel_RenderLoadingBar(panel_button_t *button)
{
	int   hunkused, hunkexpected;
	float frac;

	trap_GetHunkData(&hunkused, &hunkexpected);

	if (hunkexpected <= 0)
	{
		return;
	}

	frac = hunkused / (float)hunkexpected;
	if (frac < 0.f)
	{
		frac = 0.f;
	}
	if (frac > 1.f)
	{
		frac = 1.f;
	}

	CG_DrawPicST(button->rect.x, button->rect.y, button->rect.w * frac, button->rect.h, 0, 0, frac, 1, button->hShaderNormal);
}

/**
 * @brief CG_LoadPanel_RenderCampaignTypeText
 * @param[in] button
 */
void CG_LoadPanel_RenderCampaignTypeText(panel_button_t *button)
{
	CG_Text_Paint_Ext(button->rect.x, button->rect.y, button->font->scalex, button->font->scaley, button->font->colour, va("%s:", CG_LoadPanel_GameTypeName(cgs.gametype)), 0, 0, ITEM_TEXTSTYLE_SHADOWED, button->font->font);
}

/**
 * @brief campaignNameTextScaleFactor
 * @param[in] len
 * @return
 */
float campaignNameTextScaleFactor(int len)
{
	float scaleF = 1.f;

	//CG_Printf("CampaignNameText len: %i\n", len);

	if (len >= 27)
	{
		scaleF *= 0.8f;
		return scaleF;
	}
	// in between scale is 1
	else if (len <= 20 && len > 17)
	{
		scaleF *= 1.25f;
		return scaleF;
	}
	else if (len <= 17 && len > 13)
	{
		scaleF *= 1.5f;
		return scaleF;
	}
	else if (len <= 13)
	{
		scaleF *= 2;
		return scaleF;
	}

	return scaleF;
}

/**
 * @brief CG_LoadPanel_RenderCampaignNameText
 * @param[in] button
 */
void CG_LoadPanel_RenderCampaignNameText(panel_button_t *button)
{
	const char *cs;
	float      w;
	float      scaleF;

	if (cgs.gametype == GT_WOLF_CAMPAIGN)
	{
		cs = DC->nameForCampaign();
		if (!cs)
		{
			return;
		}

		cs = va("%s %iof%i", cs, cgs.currentCampaignMap + 1, cgs.campaignData.mapCount);

		scaleF = campaignNameTextScaleFactor(Q_PrintStrlen(cs));

		w = CG_Text_Width_Ext(cs, button->font->scalex * scaleF, 0, button->font->font);
		CG_Text_Paint_Ext(button->rect.x + (button->rect.w - w) * 0.5f, button->rect.y, button->font->scalex * scaleF, button->font->scaley * scaleF, button->font->colour, cs, 0, 0, ITEM_TEXTSTYLE_SHADOWED, button->font->font);

	}
	else
	{
		if (!cgs.arenaInfoLoaded)
		{
			return;
		}

		scaleF = campaignNameTextScaleFactor(Q_PrintStrlen(cgs.arenaData.longname)); // FIXME: up to 128 chars !

		w = CG_Text_Width_Ext(cgs.arenaData.longname, button->font->scalex * scaleF, 0, button->font->font);
		CG_Text_Paint_Ext(button->rect.x + (button->rect.w - w) * 0.5f, button->rect.y, button->font->scalex * scaleF, button->font->scaley * scaleF, button->font->colour, cgs.arenaData.longname, 0, 0, ITEM_TEXTSTYLE_SHADOWED, button->font->font);
	}
}

/**
 * @brief CG_LoadPanel_RenderMissionDescriptionText
 * @param[in] button
 */
void CG_LoadPanel_RenderMissionDescriptionText(panel_button_t *button)
{
	const char *cs;
	char       *s, *p;
	char       buffer[1024];
	float      y;

	if (cgs.gametype == GT_WOLF_CAMPAIGN)
	{
		cs = DC->descriptionForCampaign();
		if (!cs)
		{
			return;
		}

	}
	else if (cgs.gametype == GT_WOLF_LMS)
	{
		if (!cgs.arenaInfoLoaded)
		{
			return;
		}

		cs = cgs.arenaData.lmsdescription;
	}
	else
	{
		if (!cgs.arenaInfoLoaded)
		{
			return;
		}

		cs = cgs.arenaData.description;
	}

	Q_strncpyz(buffer, cs, sizeof(buffer));
	while ((s = strchr(buffer, '*')))
	{
		*s = '\n';
	}

	BG_FitTextToWidth_Ext(buffer, button->font->scalex, button->rect.w - 16, sizeof(buffer), button->font->font);

	y = button->rect.y + 12;

	s = p = buffer;
	while (*p)
	{
		if (*p == '\n')
		{
			*p++ = '\0';
			DC->drawTextExt(button->rect.x + 4, y, button->font->scalex, button->font->scaley, colorWhite, s, 0, 0, ITEM_TEXTSTYLE_SHADOWED, button->font->font);
			y += 8;
			s  = p;
		}
		else
		{
			p++;
		}
	}
}

/**
 * @brief CG_LoadPanel_KeyHandling
 * @param[in] key
 * @param[in] down
 */
void CG_LoadPanel_KeyHandling(int key, qboolean down)
{
	if (BG_PanelButtonsKeyEvent(key, down, loadpanelButtons))
	{
		return;
	}
}

/**
 * @brief Draws infoScreenText in loading bar
 * @param[in] button
 */
void CG_LoadPanel_LoadingBarText(panel_button_t *button)
{
	CG_Text_Paint_Ext(button->rect.x, button->rect.y, button->font->scalex, button->font->scaley, button->font->colour, cg.infoScreenText, 0, 0, 0, button->font->font);
}
