#include <cstdint>
#include <DataDefs.h>
#include <Core.h>
#include <Console.h>
#include <Export.h>
#include <PluginManager.h>
#include <RemoteServer.h>
#include <RemoteClient.h>
#include <VersionInfo.h>
#include "df_all.h"
#include "node.h"
#include "offsets_cache.h"


using namespace rdf;


DF_Type enum_base_type(DF_Type p_enum)
{
	switch(p_enum)
	{
		case DF_Type::ui_advmode_menu: return DF_Type::int16_t;
		case DF_Type::talk_choice_type: return DF_Type::int32_t;
		case DF_Type::announcement_type: return DF_Type::int16_t;
		case DF_Type::art_image_element_type: return DF_Type::int32_t;
		case DF_Type::art_image_property_type: return DF_Type::int32_t;
		case DF_Type::art_image_property_verb: return DF_Type::int16_t;
		case DF_Type::art_facet_type: return DF_Type::int32_t;
		case DF_Type::poetic_form_action: return DF_Type::int32_t;
		case DF_Type::poetic_form_pattern: return DF_Type::int32_t;
		case DF_Type::poetic_form_caesura_position: return DF_Type::int32_t;
		case DF_Type::poetic_form_mood: return DF_Type::int32_t;
		case DF_Type::poetic_form_subject: return DF_Type::int32_t;
		case DF_Type::poetic_form_additional_feature: return DF_Type::int32_t;
		case DF_Type::poetic_form_perspective__T_type: return DF_Type::int32_t;
		case DF_Type::occupation_type: return DF_Type::int32_t;
		case DF_Type::buildings_other_id: return DF_Type::int32_t;
		case DF_Type::building_type: return DF_Type::int32_t;
		case DF_Type::civzone_type: return DF_Type::int16_t;
		case DF_Type::furnace_type: return DF_Type::int16_t;
		case DF_Type::workshop_type: return DF_Type::int16_t;
		case DF_Type::construction_type: return DF_Type::int16_t;
		case DF_Type::shop_type: return DF_Type::int16_t;
		case DF_Type::siegeengine_type: return DF_Type::int16_t;
		case DF_Type::trap_type: return DF_Type::int16_t;
		case DF_Type::dfhack_room_quality_level: return DF_Type::int32_t;
		case DF_Type::creature_raw_flags: return DF_Type::int32_t;
		case DF_Type::caste_raw_flags: return DF_Type::int32_t;
		case DF_Type::body_part_raw_flags: return DF_Type::int32_t;
		case DF_Type::appearance_modifier_type: return DF_Type::int16_t;
		case DF_Type::body_part_layer_flags: return DF_Type::int32_t;
		case DF_Type::appearance_modifier_growth_interval: return DF_Type::int16_t;
		case DF_Type::gait_type: return DF_Type::int32_t;
		case DF_Type::creature_graphics_role: return DF_Type::int32_t;
		case DF_Type::tissue_style_type: return DF_Type::int16_t;
		case DF_Type::body_part_template_flags: return DF_Type::int32_t;
		case DF_Type::body_part_template_contype: return DF_Type::int16_t;
		case DF_Type::tissue_flags: return DF_Type::int32_t;
		case DF_Type::d_init_nickname: return DF_Type::int32_t;
		case DF_Type::d_init_z_view: return DF_Type::int32_t;
		case DF_Type::d_init_embark_confirm: return DF_Type::int32_t;
		case DF_Type::d_init_idlers: return DF_Type::int16_t;
		case DF_Type::d_init_tunnel: return DF_Type::int16_t;
		case DF_Type::d_init_flags1: return DF_Type::int32_t;
		case DF_Type::d_init_flags2: return DF_Type::int32_t;
		case DF_Type::d_init_flags3: return DF_Type::int32_t;
		case DF_Type::d_init_flags4: return DF_Type::int32_t;
		case DF_Type::pattern_type: return DF_Type::int16_t;
		case DF_Type::occasion_schedule_type: return DF_Type::int32_t;
		case DF_Type::occasion_schedule_feature: return DF_Type::int32_t;
		case DF_Type::entity_sell_category: return DF_Type::int16_t;
		case DF_Type::historical_entity_type: return DF_Type::int16_t;
		case DF_Type::training_knowledge_level: return DF_Type::int32_t;
		case DF_Type::entity_position_flags: return DF_Type::int32_t;
		case DF_Type::entity_material_category: return DF_Type::int16_t;
		case DF_Type::entity_event_type: return DF_Type::int32_t;
		case DF_Type::entity_raw_flags: return DF_Type::int32_t;
		case DF_Type::site_type: return DF_Type::int32_t;
		case DF_Type::ethic_type: return DF_Type::int32_t;
		case DF_Type::ethic_response: return DF_Type::int16_t;
		case DF_Type::entity_name_type: return DF_Type::int32_t;
		case DF_Type::entity_position_raw_flags: return DF_Type::int32_t;
		case DF_Type::entity_position_responsibility: return DF_Type::int16_t;
		case DF_Type::weather_type: return DF_Type::int8_t;
		case DF_Type::game_mode: return DF_Type::int32_t;
		case DF_Type::game_type: return DF_Type::int32_t;
		case DF_Type::lever_target_type: return DF_Type::int8_t;
		case DF_Type::zoom_commands: return DF_Type::int32_t;
		case DF_Type::reputation_type: return DF_Type::int32_t;
		case DF_Type::histfig_flags: return DF_Type::int32_t;
		case DF_Type::histfig_relationship_type: return DF_Type::int16_t;
		case DF_Type::mental_picture_property_type: return DF_Type::int32_t;
		case DF_Type::mental_picture_element_type: return DF_Type::int32_t;
		case DF_Type::history_event_type: return DF_Type::int32_t;
		case DF_Type::history_event_reason: return DF_Type::int32_t;
		case DF_Type::death_type: return DF_Type::int16_t;
		case DF_Type::entity_action_type: return DF_Type::int32_t;
		case DF_Type::masterpiece_loss_type: return DF_Type::int16_t;
		case DF_Type::history_event_hist_figure_woundedst__T_injury_type: return DF_Type::int16_t;
		case DF_Type::history_event_simple_battle_subtype: return DF_Type::int16_t;
		case DF_Type::histfig_body_state: return DF_Type::int8_t;
		case DF_Type::history_event_hf_act_on_buildingst__T_action: return DF_Type::int32_t;
		case DF_Type::site_dispute_type: return DF_Type::int32_t;
		case DF_Type::insurrection_outcome: return DF_Type::int32_t;
		case DF_Type::history_event_hf_act_on_artifactst__T_action: return DF_Type::int32_t;
		case DF_Type::tactical_situation: return DF_Type::int32_t;
		case DF_Type::history_event_collection_type: return DF_Type::int32_t;
		case DF_Type::era_type: return DF_Type::int16_t;
		case DF_Type::init_display_flags: return DF_Type::int32_t;
		case DF_Type::init_media_flags: return DF_Type::int32_t;
		case DF_Type::init_input_flags: return DF_Type::int32_t;
		case DF_Type::init_window_flags: return DF_Type::int32_t;
		case DF_Type::interaction_effect_type: return DF_Type::int32_t;
		case DF_Type::interaction_effect_location_hint: return DF_Type::int32_t;
		case DF_Type::interaction_source_type: return DF_Type::int32_t;
		case DF_Type::interaction_source_usage_hint: return DF_Type::int32_t;
		case DF_Type::interaction_target_type: return DF_Type::int32_t;
		case DF_Type::interaction_target_location_type: return DF_Type::int32_t;
		case DF_Type::breath_attack_type: return DF_Type::int16_t;
		case DF_Type::item_type: return DF_Type::int16_t;
		case DF_Type::ammo_flags: return DF_Type::int32_t;
		case DF_Type::armor_general_flags: return DF_Type::int32_t;
		case DF_Type::armor_flags: return DF_Type::int32_t;
		case DF_Type::gloves_flags: return DF_Type::int32_t;
		case DF_Type::helm_flags: return DF_Type::int32_t;
		case DF_Type::instrument_flags: return DF_Type::int32_t;
		case DF_Type::sound_production_type: return DF_Type::int32_t;
		case DF_Type::pitch_choice_type: return DF_Type::int32_t;
		case DF_Type::tuning_type: return DF_Type::int32_t;
		case DF_Type::timbre_type: return DF_Type::int32_t;
		case DF_Type::pants_flags: return DF_Type::int32_t;
		case DF_Type::shoes_flags: return DF_Type::int32_t;
		case DF_Type::tool_flags: return DF_Type::int32_t;
		case DF_Type::tool_uses: return DF_Type::int16_t;
		case DF_Type::toy_flags: return DF_Type::int32_t;
		case DF_Type::trapcomp_flags: return DF_Type::int32_t;
		case DF_Type::weapon_flags: return DF_Type::int32_t;
		case DF_Type::items_other_id: return DF_Type::int32_t;
		case DF_Type::job_item_vector_id: return DF_Type::int16_t;
		case DF_Type::improvement_type: return DF_Type::int32_t;
		case DF_Type::itemimprovement_specific_type: return DF_Type::int32_t;
		case DF_Type::written_content_type: return DF_Type::int32_t;
		case DF_Type::written_content_style: return DF_Type::int32_t;
		case DF_Type::item_magicness_type: return DF_Type::int16_t;
		case DF_Type::item_quality: return DF_Type::int16_t;
		case DF_Type::slab_engraving_type: return DF_Type::int16_t;
		case DF_Type::corpse_material_type: return DF_Type::int32_t;
		case DF_Type::job_type_class: return DF_Type::int32_t;
		case DF_Type::job_type: return DF_Type::int16_t;
		case DF_Type::job_subtype_surgery: return DF_Type::int32_t;
		case DF_Type::job_art_specification__T_type: return DF_Type::int32_t;
		case DF_Type::manager_order_condition_order__T_condition: return DF_Type::int32_t;
		case DF_Type::guild_id: return DF_Type::int16_t;
		case DF_Type::interface_key: return DF_Type::Long;
		case DF_Type::dfhack_knowledge_scholar_flag: return DF_Type::int32_t;
		case DF_Type::part_of_speech: return DF_Type::int32_t;
		case DF_Type::sphere_type: return DF_Type::int16_t;
		case DF_Type::language_name_category: return DF_Type::int32_t;
		case DF_Type::nemesis_flags: return DF_Type::int32_t;
		case DF_Type::machine_type: return DF_Type::int32_t;
		case DF_Type::screw_pump_direction: return DF_Type::int8_t;
		case DF_Type::tile_traffic: return DF_Type::uint32_t;
		case DF_Type::tile_dig_designation: return DF_Type::uint32_t;
		case DF_Type::tile_liquid: return DF_Type::uint32_t;
		case DF_Type::tile_building_occ: return DF_Type::uint32_t;
		case DF_Type::tile_liquid_flow_dir: return DF_Type::uint16_t;
		case DF_Type::block_square_event_type: return DF_Type::int32_t;
		case DF_Type::feature_type: return DF_Type::int32_t;
		case DF_Type::feature_init_flags: return DF_Type::int32_t;
		case DF_Type::feature_alteration_type: return DF_Type::int32_t;
		case DF_Type::world_construction_type: return DF_Type::int32_t;
		case DF_Type::biome_type: return DF_Type::int32_t;
		case DF_Type::flow_type: return DF_Type::int16_t;
		case DF_Type::flow_guide_type: return DF_Type::int32_t;
		case DF_Type::region_block_event_type: return DF_Type::int32_t;
		case DF_Type::craft_material_class: return DF_Type::int32_t;
		case DF_Type::builtin_mats: return DF_Type::int32_t;
		case DF_Type::material_flags: return DF_Type::int32_t;
		case DF_Type::matter_state: return DF_Type::int16_t;
		case DF_Type::strain_type: return DF_Type::int32_t;
		case DF_Type::inorganic_flags: return DF_Type::int32_t;
		case DF_Type::environment_type: return DF_Type::int16_t;
		case DF_Type::inclusion_type: return DF_Type::int16_t;
		case DF_Type::organic_mat_category: return DF_Type::int32_t;
		case DF_Type::meeting_topic: return DF_Type::int16_t;
		case DF_Type::meeting_event_type: return DF_Type::int16_t;
		case DF_Type::activity_event_type: return DF_Type::int32_t;
		case DF_Type::conversation_menu: return DF_Type::int32_t;
		case DF_Type::performance_event_type: return DF_Type::int32_t;
		case DF_Type::performance_participant_type: return DF_Type::int32_t;
		case DF_Type::uniform_category: return DF_Type::int16_t;
		case DF_Type::barrack_preference_category: return DF_Type::int32_t;
		case DF_Type::squad_event_type: return DF_Type::int16_t;
		case DF_Type::squad_order_type: return DF_Type::int32_t;
		case DF_Type::squad_order_cannot_reason: return DF_Type::int32_t;
		case DF_Type::army_flags: return DF_Type::int32_t;
		case DF_Type::unit_path_goal: return DF_Type::int16_t;
		case DF_Type::unit_station_type: return DF_Type::int16_t;
		case DF_Type::plant_raw_flags: return DF_Type::int32_t;
		case DF_Type::projectile_type: return DF_Type::int32_t;
		case DF_Type::reaction_flags: return DF_Type::int32_t;
		case DF_Type::reaction_reagent_type: return DF_Type::int32_t;
		case DF_Type::reaction_product_type: return DF_Type::int32_t;
		case DF_Type::reaction_product_item_flags: return DF_Type::int32_t;
		case DF_Type::reaction_product_improvement_flags: return DF_Type::int32_t;
		case DF_Type::general_ref_type: return DF_Type::int32_t;
		case DF_Type::specific_ref_type: return DF_Type::int32_t;
		case DF_Type::histfig_entity_link_type: return DF_Type::int32_t;
		case DF_Type::histfig_site_link_type: return DF_Type::int32_t;
		case DF_Type::histfig_hf_link_type: return DF_Type::int32_t;
		case DF_Type::entity_entity_link_type: return DF_Type::int16_t;
		case DF_Type::resource_allotment_specifier_type: return DF_Type::int32_t;
		case DF_Type::profession: return DF_Type::int16_t;
		case DF_Type::unit_labor_category: return DF_Type::int32_t;
		case DF_Type::unit_labor: return DF_Type::int32_t;
		case DF_Type::job_skill_class: return DF_Type::int32_t;
		case DF_Type::job_skill: return DF_Type::int16_t;
		case DF_Type::hauler_type: return DF_Type::int32_t;
		case DF_Type::furniture_type: return DF_Type::int32_t;
		case DF_Type::stockpile_category: return DF_Type::int16_t;
		case DF_Type::stockpile_list: return DF_Type::int32_t;
		case DF_Type::creature_interaction_effect_type: return DF_Type::int32_t;
		case DF_Type::creature_interaction_effect_target_mode: return DF_Type::int16_t;
		case DF_Type::tiletype_shape_basic: return DF_Type::int32_t;
		case DF_Type::tiletype_shape: return DF_Type::int32_t;
		case DF_Type::tiletype_material: return DF_Type::int32_t;
		case DF_Type::tiletype_variant: return DF_Type::int32_t;
		case DF_Type::tiletype_special: return DF_Type::int32_t;
		case DF_Type::tiletype: return DF_Type::int16_t;
		case DF_Type::build_req_choice_type: return DF_Type::int32_t;
		case DF_Type::ui_hotkey__T_cmd: return DF_Type::int16_t;
		case DF_Type::ui_sidebar_mode: return DF_Type::int16_t;
		case DF_Type::kitchen_exc_type: return DF_Type::int8_t;
		case DF_Type::timed_event_type: return DF_Type::int16_t;
		case DF_Type::emotion_type: return DF_Type::int32_t;
		case DF_Type::unit_thought_type: return DF_Type::int32_t;
		case DF_Type::value_type: return DF_Type::int32_t;
		case DF_Type::goal_type: return DF_Type::int32_t;
		case DF_Type::personality_facet_type: return DF_Type::uint16_t;
		case DF_Type::physical_attribute_type: return DF_Type::int32_t;
		case DF_Type::mental_attribute_type: return DF_Type::int32_t;
		case DF_Type::mood_type: return DF_Type::int16_t;
		case DF_Type::ghost_type: return DF_Type::int16_t;
		case DF_Type::animal_training_level: return DF_Type::int32_t;
		case DF_Type::unit_report_type: return DF_Type::int16_t;
		case DF_Type::skill_rating: return DF_Type::int32_t;
		case DF_Type::unit_relationship_type: return DF_Type::int16_t;
		case DF_Type::need_type: return DF_Type::int32_t;
		case DF_Type::ghost_goal: return DF_Type::int16_t;
		case DF_Type::wound_effect_type: return DF_Type::int16_t;
		case DF_Type::misc_trait_type: return DF_Type::int16_t;
		case DF_Type::unit_action_type: return DF_Type::int32_t;
		case DF_Type::interface_breakdown_types: return DF_Type::int8_t;
		case DF_Type::embark_finder_option: return DF_Type::int32_t;
		case DF_Type::viewscreen_image_creator_mode: return DF_Type::int32_t;
		case DF_Type::viewscreen_kitchenpref_page: return DF_Type::int32_t;
		case DF_Type::adventurer_attribute_level: return DF_Type::int32_t;
		case DF_Type::viewscreen_unitlist_page: return DF_Type::int32_t;
		case DF_Type::world_population_type: return DF_Type::int32_t;
		case DF_Type::world_region_type: return DF_Type::int16_t;
		case DF_Type::geo_layer_type: return DF_Type::int16_t;
		case DF_Type::region_map_entry_flags: return DF_Type::int32_t;
		case DF_Type::front_type: return DF_Type::uint16_t;
		case DF_Type::cumulus_type: return DF_Type::uint16_t;
		case DF_Type::stratus_type: return DF_Type::uint16_t;
		case DF_Type::fog_type: return DF_Type::uint16_t;
		case DF_Type::mountain_peak_flags: return DF_Type::int32_t;
		case DF_Type::abstract_building_type: return DF_Type::int32_t;
		case DF_Type::abstract_building_flags: return DF_Type::int32_t;
		case DF_Type::world_site_type: return DF_Type::int16_t;
		case DF_Type::world_site_flags: return DF_Type::int32_t;
		case DF_Type::site_realization_building_type: return DF_Type::int32_t;
		case DF_Type::site_shop_type: return DF_Type::int32_t;
		case DF_Type::tree_house_type: return DF_Type::int32_t;
		case DF_Type::hillock_house_type: return DF_Type::int32_t;
		case DF_Type::creation_zone_pwg_alteration_type: return DF_Type::int32_t;
		case DF_Type::worldgen_region_type: return DF_Type::int32_t;
		case DF_Type::worldgen_range_type: return DF_Type::int32_t;
		case DF_Type::units_other_id: return DF_Type::int32_t;
		case DF_Type::conflict_level: return DF_Type::int32_t;
		case DF_Type::combat_report_event_type: return DF_Type::int16_t;
		case DF_Type::conversation__T_state: return DF_Type::int32_t;
		case DF_Type::building_archerytargetst__T_archery_direction: return DF_Type::int8_t;
		case DF_Type::building_bridgest__T_direction: return DF_Type::int8_t;
		case DF_Type::building_siegeenginest__T_facing: return DF_Type::int8_t;
		case DF_Type::building_siegeenginest__T_action: return DF_Type::int8_t;
		case DF_Type::caste_body_info__T_interactions__T_type: return DF_Type::int32_t;
		case DF_Type::caravan_state__T_trade_state: return DF_Type::int8_t;
		case DF_Type::entity_event__T_data__T_insurrection_end__T_result: return DF_Type::int32_t;
		case DF_Type::history_event_change_hf_statest__T_state: return DF_Type::int16_t;
		case DF_Type::history_event_body_abusedst__T_props__T_pile_type: return DF_Type::int32_t;
		case DF_Type::history_event_body_abusedst__T_abuse_type: return DF_Type::int16_t;
		case DF_Type::history_event_hist_figure_travelst__T_reason: return DF_Type::int32_t;
		case DF_Type::history_event_artifact_claim_formedst__T_claim_type: return DF_Type::int32_t;
		case DF_Type::init_display__T_windowed: return DF_Type::int32_t;
		case DF_Type::init_font__T_use_ttf: return DF_Type::int32_t;
		case DF_Type::job_item_ref__T_role: return DF_Type::int32_t;
		case DF_Type::manager_order__T_frequency: return DF_Type::int32_t;
		case DF_Type::manager_order_condition_item__T_compare_type: return DF_Type::int32_t;
		case DF_Type::mandate__T_mode: return DF_Type::int16_t;
		case DF_Type::unit_demand__T_place: return DF_Type::int16_t;
		case DF_Type::ui_advmode__T_conversation__T_targets__T_type: return DF_Type::int32_t;
		case DF_Type::ui_advmode__T_travel_right_map: return DF_Type::int8_t;
		case DF_Type::ui_advmode__T_show_menu: return DF_Type::int8_t;
		case DF_Type::stop_depart_condition__T_direction: return DF_Type::int32_t;
		case DF_Type::stop_depart_condition__T_mode: return DF_Type::int32_t;
		case DF_Type::interface_button_construction_category_selectorst__T_category_id: return DF_Type::int32_t;
		case DF_Type::ui_sidebar_menus__T_designation__T_mine_mode: return DF_Type::int32_t;
		case DF_Type::ui_sidebar_menus__T_zone__T_mode: return DF_Type::int16_t;
		case DF_Type::ui_sidebar_menus__T_unit__T_expel_error: return DF_Type::int32_t;
		case DF_Type::ui_look_list__T_items__T_type: return DF_Type::int16_t;
		case DF_Type::ui_unit_view_mode__T_value: return DF_Type::int32_t;
		case DF_Type::unit__T_meeting__T_state: return DF_Type::int8_t;
		case DF_Type::unit__T_counters__T_soldier_mood: return DF_Type::int16_t;
		case DF_Type::unit_inventory_item__T_mode: return DF_Type::int16_t;
		case DF_Type::unit_preference__T_type: return DF_Type::int16_t;
		case DF_Type::unit_complaint__T_type: return DF_Type::int32_t;
		case DF_Type::unit_request__T_type: return DF_Type::int16_t;
		case DF_Type::KeybindingScreen__T_mode: return DF_Type::int32_t;
		case DF_Type::viewscreen_adventure_logst__T_mode: return DF_Type::int8_t;
		case DF_Type::viewscreen_adventure_logst__T_info_mode: return DF_Type::int16_t;
		case DF_Type::viewscreen_assign_display_itemst__T_sel_column: return DF_Type::int32_t;
		case DF_Type::viewscreen_choose_start_sitest__T_page: return DF_Type::int32_t;
		case DF_Type::mission__T_details__T_raid__T_raid_type: return DF_Type::int32_t;
		case DF_Type::mission__T_type: return DF_Type::int32_t;
		case DF_Type::viewscreen_civlistst__T_rumors__T_type: return DF_Type::int32_t;
		case DF_Type::viewscreen_civlistst__T_page: return DF_Type::int32_t;
		case DF_Type::viewscreen_game_cleanerst__T_state: return DF_Type::int32_t;
		case DF_Type::viewscreen_justicest__T_cur_column: return DF_Type::int32_t;
		case DF_Type::assign_trade_status__T_status: return DF_Type::int8_t;
		case DF_Type::viewscreen_layer_choose_language_namest__T_current_component: return DF_Type::int32_t;
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_mode: return DF_Type::int32_t;
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_edit_mode: return DF_Type::int32_t;
		case DF_Type::viewscreen_layer_militaryst__T_page: return DF_Type::int32_t;
		case DF_Type::viewscreen_layer_noblelistst__T_mode: return DF_Type::int16_t;
		case DF_Type::viewscreen_legendsst__T_cur_page: return DF_Type::int16_t;
		case DF_Type::viewscreen_locationsst__T_in_edit: return DF_Type::int32_t;
		case DF_Type::viewscreen_locationsst__T_menu: return DF_Type::int32_t;
		case DF_Type::viewscreen_petst__T_mode: return DF_Type::int32_t;
		case DF_Type::setup_character_info__T_status: return DF_Type::int16_t;
		case DF_Type::viewscreen_setupadventurest__T_page: return DF_Type::int32_t;
		case DF_Type::viewscreen_setupadventurest__T_sel_trait_column: return DF_Type::int8_t;
		case DF_Type::viewscreen_setupdwarfgamest__T_mode: return DF_Type::int32_t;
		case DF_Type::viewscreen_titlest__T_sel_subpage: return DF_Type::int16_t;
		case DF_Type::viewscreen_workquota_conditionst__T_mode: return DF_Type::int32_t;
		case DF_Type::viewscreen_workshop_profilest__T_tab: return DF_Type::int32_t;
		case DF_Type::world_underground_region__T_type: return DF_Type::int16_t;
		case DF_Type::world_data__T_flip_latitude: return DF_Type::int16_t;
		case DF_Type::abstract_building_dungeonst__T_dungeon_type: return DF_Type::int16_t;
		case DF_Type::cultural_identity__T_group_log__T_join_type: return DF_Type::int32_t;
		case DF_Type::world_site_realization__T_areas__T_type: return DF_Type::int32_t;
		case DF_Type::crime__T_mode: return DF_Type::int32_t;
		default: break;
	}
	return DF_Type::None;
}

