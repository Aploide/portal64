
local sk_definition_writer = require('sk_definition_writer')
local sk_math = require('sk_math')
local static_export = require('tools.level_scripts.static_export')
local collision_export = require('tools.level_scripts.collision_export')
local portal_surfaces = require('tools.level_scripts.portal_surfaces')
local trigger = require('tools.level_scripts.trigger')
local world = require('tools.level_scripts.world')

sk_definition_writer.add_definition("level", "struct LevelDefinition", "_geo", {
    collisionQuads = sk_definition_writer.reference_to(collision_export.collision_objects, 1),
    collisionQuadCount = #collision_export.collision_objects,
    staticContent = sk_definition_writer.reference_to(static_export.static_content_elements, 1),
    staticContentCount = #static_export.static_content_elements,
    roomStaticMapping = sk_definition_writer.reference_to(static_export.room_ranges, 1),
    portalSurfaces = sk_definition_writer.reference_to(portal_surfaces.portal_surfaces, 1),
    portalSurfaceCount = #portal_surfaces.portal_surfaces,
    portalSurfaceMappingRange = sk_definition_writer.reference_to(portal_surfaces.portal_mapping_range, 1),
    portalSurfaceMappingIndices = sk_definition_writer.reference_to(portal_surfaces.portal_mapping_data, 1),
    triggers = sk_definition_writer.reference_to(trigger.triggers, 1),
    triggerCount = #trigger.triggers,
    cutscenes = sk_definition_writer.reference_to(trigger.cutscene_data, 1),
    cutsceneCount = #trigger.cutscene_data,
    locations = sk_definition_writer.reference_to(trigger.location_data, 1),
    locationCount = #trigger.location_data,
    startLocation = trigger.find_location_index("start"),
    world = world.world,
})