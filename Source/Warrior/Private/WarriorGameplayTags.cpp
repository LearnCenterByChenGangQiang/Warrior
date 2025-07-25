// ChenGangQiang All rights Reserved.


#include "WarriorGameplayTags.h"


namespace WarriorGameplayTags
{
	/** Input Tags */
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "Input.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "Input.Look");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_EquipAxe, "Input.EquipAxe");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_UnequipAxe, "Input.UnequipAxe");

	/** player tags */
	UE_DEFINE_GAMEPLAY_TAG(Player_WeaponAxe, "Player.Weapon.Axe");

	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Equip_Axe, "Player.Event.Equip.Axe");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Unequip_Axe, "Player.Event.Unequip.Axe");
}

