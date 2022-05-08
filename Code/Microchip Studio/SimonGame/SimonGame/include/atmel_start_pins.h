/*
 * Code generated from START.
 *
 * This file will be overwritten when reconfiguring your START project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef ATMEL_START_PINS_H_INCLUDED
#define ATMEL_START_PINS_H_INCLUDED

#include <port.h>

/**
 * \brief Set SPEAKER pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void SPEAKER_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTA_set_pin_pull_mode(1, pull_mode);
}

/**
 * \brief Set SPEAKER data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void SPEAKER_set_dir(const enum port_dir dir)
{
	PORTA_set_pin_dir(1, dir);
}

/**
 * \brief Set SPEAKER input/sense configuration
 *
 * Enable/disable SPEAKER digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void SPEAKER_set_isc(const PORT_ISC_t isc)
{
	PORTA_pin_set_isc(1, isc);
}

/**
 * \brief Set SPEAKER inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on SPEAKER is inverted
 *                     false = I/O on SPEAKER is not inverted
 */
static inline void SPEAKER_set_inverted(const bool inverted)
{
	PORTA_pin_set_inverted(1, inverted);
}

/**
 * \brief Set SPEAKER level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void SPEAKER_set_level(const bool level)
{
	PORTA_set_pin_level(1, level);
}

/**
 * \brief Toggle output level on SPEAKER
 *
 * Toggle the pin level
 */
static inline void SPEAKER_toggle_level()
{
	PORTA_toggle_pin_level(1);
}

/**
 * \brief Get level on SPEAKER
 *
 * Reads the level on a pin
 */
static inline bool SPEAKER_get_level()
{
	return PORTA_get_pin_level(1);
}

/**
 * \brief Set SEG0EN pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void SEG0EN_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTA_set_pin_pull_mode(2, pull_mode);
}

/**
 * \brief Set SEG0EN data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void SEG0EN_set_dir(const enum port_dir dir)
{
	PORTA_set_pin_dir(2, dir);
}

/**
 * \brief Set SEG0EN input/sense configuration
 *
 * Enable/disable SEG0EN digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void SEG0EN_set_isc(const PORT_ISC_t isc)
{
	PORTA_pin_set_isc(2, isc);
}

/**
 * \brief Set SEG0EN inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on SEG0EN is inverted
 *                     false = I/O on SEG0EN is not inverted
 */
static inline void SEG0EN_set_inverted(const bool inverted)
{
	PORTA_pin_set_inverted(2, inverted);
}

/**
 * \brief Set SEG0EN level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void SEG0EN_set_level(const bool level)
{
	PORTA_set_pin_level(2, level);
}

/**
 * \brief Toggle output level on SEG0EN
 *
 * Toggle the pin level
 */
static inline void SEG0EN_toggle_level()
{
	PORTA_toggle_pin_level(2);
}

/**
 * \brief Get level on SEG0EN
 *
 * Reads the level on a pin
 */
static inline bool SEG0EN_get_level()
{
	return PORTA_get_pin_level(2);
}

/**
 * \brief Set SEG1EN pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void SEG1EN_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTA_set_pin_pull_mode(3, pull_mode);
}

/**
 * \brief Set SEG1EN data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void SEG1EN_set_dir(const enum port_dir dir)
{
	PORTA_set_pin_dir(3, dir);
}

/**
 * \brief Set SEG1EN input/sense configuration
 *
 * Enable/disable SEG1EN digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void SEG1EN_set_isc(const PORT_ISC_t isc)
{
	PORTA_pin_set_isc(3, isc);
}

/**
 * \brief Set SEG1EN inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on SEG1EN is inverted
 *                     false = I/O on SEG1EN is not inverted
 */
static inline void SEG1EN_set_inverted(const bool inverted)
{
	PORTA_pin_set_inverted(3, inverted);
}

/**
 * \brief Set SEG1EN level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void SEG1EN_set_level(const bool level)
{
	PORTA_set_pin_level(3, level);
}

/**
 * \brief Toggle output level on SEG1EN
 *
 * Toggle the pin level
 */
static inline void SEG1EN_toggle_level()
{
	PORTA_toggle_pin_level(3);
}

/**
 * \brief Get level on SEG1EN
 *
 * Reads the level on a pin
 */
static inline bool SEG1EN_get_level()
{
	return PORTA_get_pin_level(3);
}

/**
 * \brief Set SEG0 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void SEG0_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTA_set_pin_pull_mode(4, pull_mode);
}

/**
 * \brief Set SEG0 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void SEG0_set_dir(const enum port_dir dir)
{
	PORTA_set_pin_dir(4, dir);
}

/**
 * \brief Set SEG0 input/sense configuration
 *
 * Enable/disable SEG0 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void SEG0_set_isc(const PORT_ISC_t isc)
{
	PORTA_pin_set_isc(4, isc);
}

/**
 * \brief Set SEG0 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on SEG0 is inverted
 *                     false = I/O on SEG0 is not inverted
 */
static inline void SEG0_set_inverted(const bool inverted)
{
	PORTA_pin_set_inverted(4, inverted);
}

/**
 * \brief Set SEG0 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void SEG0_set_level(const bool level)
{
	PORTA_set_pin_level(4, level);
}

/**
 * \brief Toggle output level on SEG0
 *
 * Toggle the pin level
 */
static inline void SEG0_toggle_level()
{
	PORTA_toggle_pin_level(4);
}

/**
 * \brief Get level on SEG0
 *
 * Reads the level on a pin
 */
static inline bool SEG0_get_level()
{
	return PORTA_get_pin_level(4);
}

/**
 * \brief Set SEG1 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void SEG1_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTA_set_pin_pull_mode(5, pull_mode);
}

/**
 * \brief Set SEG1 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void SEG1_set_dir(const enum port_dir dir)
{
	PORTA_set_pin_dir(5, dir);
}

/**
 * \brief Set SEG1 input/sense configuration
 *
 * Enable/disable SEG1 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void SEG1_set_isc(const PORT_ISC_t isc)
{
	PORTA_pin_set_isc(5, isc);
}

/**
 * \brief Set SEG1 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on SEG1 is inverted
 *                     false = I/O on SEG1 is not inverted
 */
static inline void SEG1_set_inverted(const bool inverted)
{
	PORTA_pin_set_inverted(5, inverted);
}

/**
 * \brief Set SEG1 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void SEG1_set_level(const bool level)
{
	PORTA_set_pin_level(5, level);
}

/**
 * \brief Toggle output level on SEG1
 *
 * Toggle the pin level
 */
static inline void SEG1_toggle_level()
{
	PORTA_toggle_pin_level(5);
}

/**
 * \brief Get level on SEG1
 *
 * Reads the level on a pin
 */
static inline bool SEG1_get_level()
{
	return PORTA_get_pin_level(5);
}

/**
 * \brief Set SEG2 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void SEG2_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTA_set_pin_pull_mode(6, pull_mode);
}

/**
 * \brief Set SEG2 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void SEG2_set_dir(const enum port_dir dir)
{
	PORTA_set_pin_dir(6, dir);
}

/**
 * \brief Set SEG2 input/sense configuration
 *
 * Enable/disable SEG2 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void SEG2_set_isc(const PORT_ISC_t isc)
{
	PORTA_pin_set_isc(6, isc);
}

/**
 * \brief Set SEG2 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on SEG2 is inverted
 *                     false = I/O on SEG2 is not inverted
 */
static inline void SEG2_set_inverted(const bool inverted)
{
	PORTA_pin_set_inverted(6, inverted);
}

/**
 * \brief Set SEG2 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void SEG2_set_level(const bool level)
{
	PORTA_set_pin_level(6, level);
}

/**
 * \brief Toggle output level on SEG2
 *
 * Toggle the pin level
 */
static inline void SEG2_toggle_level()
{
	PORTA_toggle_pin_level(6);
}

/**
 * \brief Get level on SEG2
 *
 * Reads the level on a pin
 */
static inline bool SEG2_get_level()
{
	return PORTA_get_pin_level(6);
}

/**
 * \brief Set LED_R pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void LED_R_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTB_set_pin_pull_mode(0, pull_mode);
}

/**
 * \brief Set LED_R data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void LED_R_set_dir(const enum port_dir dir)
{
	PORTB_set_pin_dir(0, dir);
}

/**
 * \brief Set LED_R input/sense configuration
 *
 * Enable/disable LED_R digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void LED_R_set_isc(const PORT_ISC_t isc)
{
	PORTB_pin_set_isc(0, isc);
}

/**
 * \brief Set LED_R inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on LED_R is inverted
 *                     false = I/O on LED_R is not inverted
 */
static inline void LED_R_set_inverted(const bool inverted)
{
	PORTB_pin_set_inverted(0, inverted);
}

/**
 * \brief Set LED_R level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void LED_R_set_level(const bool level)
{
	PORTB_set_pin_level(0, level);
}

/**
 * \brief Toggle output level on LED_R
 *
 * Toggle the pin level
 */
static inline void LED_R_toggle_level()
{
	PORTB_toggle_pin_level(0);
}

/**
 * \brief Get level on LED_R
 *
 * Reads the level on a pin
 */
static inline bool LED_R_get_level()
{
	return PORTB_get_pin_level(0);
}

/**
 * \brief Set LED_Y pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void LED_Y_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTB_set_pin_pull_mode(1, pull_mode);
}

/**
 * \brief Set LED_Y data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void LED_Y_set_dir(const enum port_dir dir)
{
	PORTB_set_pin_dir(1, dir);
}

/**
 * \brief Set LED_Y input/sense configuration
 *
 * Enable/disable LED_Y digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void LED_Y_set_isc(const PORT_ISC_t isc)
{
	PORTB_pin_set_isc(1, isc);
}

/**
 * \brief Set LED_Y inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on LED_Y is inverted
 *                     false = I/O on LED_Y is not inverted
 */
static inline void LED_Y_set_inverted(const bool inverted)
{
	PORTB_pin_set_inverted(1, inverted);
}

/**
 * \brief Set LED_Y level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void LED_Y_set_level(const bool level)
{
	PORTB_set_pin_level(1, level);
}

/**
 * \brief Toggle output level on LED_Y
 *
 * Toggle the pin level
 */
static inline void LED_Y_toggle_level()
{
	PORTB_toggle_pin_level(1);
}

/**
 * \brief Get level on LED_Y
 *
 * Reads the level on a pin
 */
static inline bool LED_Y_get_level()
{
	return PORTB_get_pin_level(1);
}

/**
 * \brief Set LED_G pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void LED_G_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTB_set_pin_pull_mode(2, pull_mode);
}

/**
 * \brief Set LED_G data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void LED_G_set_dir(const enum port_dir dir)
{
	PORTB_set_pin_dir(2, dir);
}

/**
 * \brief Set LED_G input/sense configuration
 *
 * Enable/disable LED_G digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void LED_G_set_isc(const PORT_ISC_t isc)
{
	PORTB_pin_set_isc(2, isc);
}

/**
 * \brief Set LED_G inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on LED_G is inverted
 *                     false = I/O on LED_G is not inverted
 */
static inline void LED_G_set_inverted(const bool inverted)
{
	PORTB_pin_set_inverted(2, inverted);
}

/**
 * \brief Set LED_G level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void LED_G_set_level(const bool level)
{
	PORTB_set_pin_level(2, level);
}

/**
 * \brief Toggle output level on LED_G
 *
 * Toggle the pin level
 */
static inline void LED_G_toggle_level()
{
	PORTB_toggle_pin_level(2);
}

/**
 * \brief Get level on LED_G
 *
 * Reads the level on a pin
 */
static inline bool LED_G_get_level()
{
	return PORTB_get_pin_level(2);
}

/**
 * \brief Set LED_B pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void LED_B_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTB_set_pin_pull_mode(3, pull_mode);
}

/**
 * \brief Set LED_B data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void LED_B_set_dir(const enum port_dir dir)
{
	PORTB_set_pin_dir(3, dir);
}

/**
 * \brief Set LED_B input/sense configuration
 *
 * Enable/disable LED_B digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void LED_B_set_isc(const PORT_ISC_t isc)
{
	PORTB_pin_set_isc(3, isc);
}

/**
 * \brief Set LED_B inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on LED_B is inverted
 *                     false = I/O on LED_B is not inverted
 */
static inline void LED_B_set_inverted(const bool inverted)
{
	PORTB_pin_set_inverted(3, inverted);
}

/**
 * \brief Set LED_B level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void LED_B_set_level(const bool level)
{
	PORTB_set_pin_level(3, level);
}

/**
 * \brief Toggle output level on LED_B
 *
 * Toggle the pin level
 */
static inline void LED_B_toggle_level()
{
	PORTB_toggle_pin_level(3);
}

/**
 * \brief Get level on LED_B
 *
 * Reads the level on a pin
 */
static inline bool LED_B_get_level()
{
	return PORTB_get_pin_level(3);
}

/**
 * \brief Set BTN_R pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void BTN_R_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTC_set_pin_pull_mode(0, pull_mode);
}

/**
 * \brief Set BTN_R data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void BTN_R_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(0, dir);
}

/**
 * \brief Set BTN_R input/sense configuration
 *
 * Enable/disable BTN_R digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void BTN_R_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(0, isc);
}

/**
 * \brief Set BTN_R inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on BTN_R is inverted
 *                     false = I/O on BTN_R is not inverted
 */
static inline void BTN_R_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(0, inverted);
}

/**
 * \brief Set BTN_R level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void BTN_R_set_level(const bool level)
{
	PORTC_set_pin_level(0, level);
}

/**
 * \brief Toggle output level on BTN_R
 *
 * Toggle the pin level
 */
static inline void BTN_R_toggle_level()
{
	PORTC_toggle_pin_level(0);
}

/**
 * \brief Get level on BTN_R
 *
 * Reads the level on a pin
 */
static inline bool BTN_R_get_level()
{
	return PORTC_get_pin_level(0);
}

/**
 * \brief Set BTN_Y pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void BTN_Y_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTC_set_pin_pull_mode(1, pull_mode);
}

/**
 * \brief Set BTN_Y data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void BTN_Y_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(1, dir);
}

/**
 * \brief Set BTN_Y input/sense configuration
 *
 * Enable/disable BTN_Y digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void BTN_Y_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(1, isc);
}

/**
 * \brief Set BTN_Y inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on BTN_Y is inverted
 *                     false = I/O on BTN_Y is not inverted
 */
static inline void BTN_Y_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(1, inverted);
}

/**
 * \brief Set BTN_Y level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void BTN_Y_set_level(const bool level)
{
	PORTC_set_pin_level(1, level);
}

/**
 * \brief Toggle output level on BTN_Y
 *
 * Toggle the pin level
 */
static inline void BTN_Y_toggle_level()
{
	PORTC_toggle_pin_level(1);
}

/**
 * \brief Get level on BTN_Y
 *
 * Reads the level on a pin
 */
static inline bool BTN_Y_get_level()
{
	return PORTC_get_pin_level(1);
}

/**
 * \brief Set BTN_G pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void BTN_G_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTC_set_pin_pull_mode(2, pull_mode);
}

/**
 * \brief Set BTN_G data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void BTN_G_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(2, dir);
}

/**
 * \brief Set BTN_G input/sense configuration
 *
 * Enable/disable BTN_G digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void BTN_G_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(2, isc);
}

/**
 * \brief Set BTN_G inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on BTN_G is inverted
 *                     false = I/O on BTN_G is not inverted
 */
static inline void BTN_G_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(2, inverted);
}

/**
 * \brief Set BTN_G level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void BTN_G_set_level(const bool level)
{
	PORTC_set_pin_level(2, level);
}

/**
 * \brief Toggle output level on BTN_G
 *
 * Toggle the pin level
 */
static inline void BTN_G_toggle_level()
{
	PORTC_toggle_pin_level(2);
}

/**
 * \brief Get level on BTN_G
 *
 * Reads the level on a pin
 */
static inline bool BTN_G_get_level()
{
	return PORTC_get_pin_level(2);
}

/**
 * \brief Set BTN_B pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void BTN_B_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTC_set_pin_pull_mode(3, pull_mode);
}

/**
 * \brief Set BTN_B data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void BTN_B_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(3, dir);
}

/**
 * \brief Set BTN_B input/sense configuration
 *
 * Enable/disable BTN_B digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void BTN_B_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(3, isc);
}

/**
 * \brief Set BTN_B inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on BTN_B is inverted
 *                     false = I/O on BTN_B is not inverted
 */
static inline void BTN_B_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(3, inverted);
}

/**
 * \brief Set BTN_B level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void BTN_B_set_level(const bool level)
{
	PORTC_set_pin_level(3, level);
}

/**
 * \brief Toggle output level on BTN_B
 *
 * Toggle the pin level
 */
static inline void BTN_B_toggle_level()
{
	PORTC_toggle_pin_level(3);
}

/**
 * \brief Get level on BTN_B
 *
 * Reads the level on a pin
 */
static inline bool BTN_B_get_level()
{
	return PORTC_get_pin_level(3);
}

#endif /* ATMEL_START_PINS_H_INCLUDED */
