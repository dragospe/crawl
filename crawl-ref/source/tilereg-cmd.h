#ifdef USE_TILE_LOCAL
#ifndef TILEREG_CMD_H
#define TILEREG_CMD_H

#include <vector>

#include "tilereg-grid.h"

static const command_type ct_system_commands[] =
{
    // informational commands
    CMD_REPLAY_MESSAGES, CMD_RESISTS_SCREEN, CMD_DISPLAY_OVERMAP,
    CMD_DISPLAY_RELIGION, CMD_DISPLAY_MUTATIONS, CMD_DISPLAY_SKILLS,
    CMD_DISPLAY_CHARACTER_STATUS, CMD_DISPLAY_KNOWN_OBJECTS,

    // meta commands
    CMD_SAVE_GAME_NOW, CMD_EDIT_PLAYER_TILE, CMD_DISPLAY_COMMANDS
};

static const command_type ct_map_commands[] =
{
    CMD_DISPLAY_MAP,
    CMD_MAP_GOTO_TARGET,

    CMD_MAP_NEXT_LEVEL,
    CMD_MAP_PREV_LEVEL,
    CMD_MAP_GOTO_LEVEL,

    CMD_MAP_EXCLUDE_AREA,
    CMD_MAP_FIND_EXCLUDED,
    CMD_MAP_CLEAR_EXCLUDES,

    CMD_MAP_ADD_WAYPOINT,
    CMD_MAP_FIND_WAYPOINT,

    CMD_MAP_FIND_UPSTAIR,
    CMD_MAP_FIND_DOWNSTAIR,
    CMD_MAP_FIND_YOU,
    CMD_MAP_FIND_PORTAL,
    CMD_MAP_FIND_TRAP,
    CMD_MAP_FIND_ALTAR,
//    CMD_MAP_FIND_F,  // no-one knows what this is for, so it's been taken out :P

    CMD_MAP_FIND_STASH,
};

static const command_type ct_action_commands[] =
{
    // action commands
    CMD_EXPLORE,
# ifdef CLUA_BINDINGS
    CMD_AUTOFIGHT,
# endif
    CMD_REST,
    CMD_DISPLAY_INVENTORY, CMD_CAST_SPELL, CMD_USE_ABILITY,
    CMD_PRAY, CMD_BUTCHER, CMD_DROP,
    CMD_INTERLEVEL_TRAVEL, CMD_WAIT, CMD_SEARCH_STASHES,

    // commonly used screens
    CMD_DISPLAY_SKILLS, CMD_MEMORISE_SPELL
};

class CommandRegion : public GridRegion
{
public:
    CommandRegion(const TileRegionInit &init, const command_type commands[],
                  const int n_commands, const string name="Commands",
                  const string help="Execute commands");
    int n_common_commands;

    virtual void update();
    virtual int handle_mouse(MouseEvent &event);
    virtual bool update_tip_text(string &tip);
    virtual bool update_tab_tip_text(string &tip, bool active);
    virtual bool update_alt_text(string &alt);

    virtual const string name() const { return m_name; }

protected:
    virtual void pack_buffers();
    virtual void draw_tag();
    virtual void activate();

private:
    vector<command_type> _common_commands;
    string m_name;
    string m_help;
};

#endif
#endif
