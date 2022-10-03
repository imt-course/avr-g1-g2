/*
 * Icu.h
 *
 *  Created on: Oct 1, 2022
 *      Author: ahmad
 */

#ifndef INC_ICU_H_
#define INC_ICU_H_

typedef enum {
    ICU_EDGE_FALLING,
    ICU_EDGE_RISING
} Icu_EdgeType;

void Icu_Init();
void Icu_SetEdge(Icu_EdgeType edge);
void Icu_EnableNotifications(void (*callback) (u16 value));
void Icu_DisableNotification(void);

#endif /* INC_ICU_H_ */
