#include <stdio.h>
#include <stdbool.h>
#include "object.h"
#include "misc.h"
#include "match.h"
#include "noun.h"
#include "move.h"

int executeGet(void) {
	OBJECT *obj = getVisible("what you want to get", params[0]);
	switch (getDistance(player, obj)) {
		case distSelf:
			printf("You shouldn't be doing that to yourself. \n");
			break;
		case distHeld:
			printf("You already have %s.\n", obj->description);
			break;
		case distOverthere:
			printf("Too far away, move closer please.\n");
			break;
		case distUnknownObject:
			// already handled by getVisible
			break;
		default:
			if (obj->location != NULL && obj->location->health > 0) {
				printf("You should ask %s nicely.\n", obj->location->description);
			}
			else if (obj->location == shopkeeper) {
				printf("Bring something more valuable for %s next time.\n", obj->location->description);
			}
			else {
				moveObject(obj, player);
			}
	}
	return 1;
}

int executeDrop(void) {
	moveObject(getPossession(player, "drop", params[0]), player->location);
	return 1;
}

int executeAsk(void) {
	moveObject(getPossession(actorHere(), "ask", params[0]), player);
	return 1;
}

int executeGive(void) {
	moveObject(getPossession(player, "give", params[0]), actorHere());
	return 1;
}

int executeInventory(void) {
	if (listObjectsAtLocation(player) == 0) {
		printf("You are empty-handed.\n");
	}
	return 1;
}
