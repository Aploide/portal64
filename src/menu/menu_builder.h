#ifndef __MENU_MENU_BUILDER_H__
#define __MENU_MENU_BUILDER_H__

#include "../font/font.h"
#include "./menu.h"
#include "../graphics/renderstate.h"

#include <ctype.h>

struct MenuBuilderElement;
struct MenuElementParams;

enum MenuElementType {
    MenuElementTypeText,
    MenuElementTypeCheckbox,
    MenuElementTypeSlider,
};

struct MenuAction {
    enum MenuElementType type;
    union
    {
        struct {
            unsigned char isChecked;
        } checkbox;
        struct {
            float value;
        } fSlider;
        struct {
            short value;
        } iSlider;
    } state;
};

typedef void (*MenuActionCalback)(void* data, int selection, struct MenuAction* action);

typedef void (*MenuItemInit)(struct MenuBuilderElement* element);
typedef enum MenuDirection (*MenuItemUpdate)(struct MenuBuilderElement* element, MenuActionCalback actionCallback, void* data);
typedef void (*MenuItemRebuildText)(struct MenuBuilderElement* element);
typedef void (*MenuItemRender)(struct MenuBuilderElement* element, int selection, int materialIndex, struct PrerenderedTextBatch* textBatch, struct RenderState* renderState);

struct MenuBuilderCallbacks {
    MenuItemInit init;
    MenuItemUpdate update;
    MenuItemRebuildText rebuildText;
    MenuItemRender render;
};

struct MenuElementParams {
    enum MenuElementType type;
    short x;
    short y;
    union
    {
        struct {
            struct Font* font;
            short messageId;
        } text;
        struct {
            struct Font* font;
            short messageId;
        } checkbox;
        struct {
            struct Font* font;
            short messageId;
            short width;
            short numberOfTicks;
            short discrete;
        } slider;
    } params;
    short selectionIndex;
};

struct MenuBuilderElement {
    void* data;
    struct MenuBuilderCallbacks* callbacks;
    struct MenuElementParams* params;
    short selectionIndex;
};

struct MenuBuilder {
    struct MenuBuilderElement* elements;
    MenuActionCalback actionCallback;
    void* data;
    short elementCount;
    short selection;
    short maxSelection;
};

void menuBuilderInit(
    struct MenuBuilder* menuBuilder, 
    struct MenuElementParams* params, 
    int elementCount, 
    int maxSelection, 
    MenuActionCalback actionCallback, 
    void* data
);
enum MenuDirection menuBuilderUpdate(struct MenuBuilder* menuBuilder);
void menuBuilderRebuildText(struct MenuBuilder* menuBuilder);
void menuBuilderRender(struct MenuBuilder* menuBuilder, struct RenderState* renderState);

#endif