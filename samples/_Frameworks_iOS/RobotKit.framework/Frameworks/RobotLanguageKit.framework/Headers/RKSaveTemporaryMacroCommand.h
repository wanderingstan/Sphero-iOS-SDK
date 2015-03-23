//
//  Copyright 2011-2014 Orbotix Inc. All rights reserved.
//

/*! @file */

#import <RobotCommandKit/RKDeviceCommand.h>

/*! Enumerations for the various flags that can be set for a macro. Multiple flags can be
 set by using a bitwise or operation on them. */
typedef NS_ENUM(uint8_t, RKMacroFlags) {
   RKMacroFlagNone = 0x0000, /*!< Used when no flags are to be set. */
      RKMacroFlagMotorControl = 0x0001, /*!< Kills the drive motors on exit or abort. */
      RKMacroFlagExclusiveDrive = 0x0002, /*!< Gives the macro exclusive control of driving. */
      RKMacroFlagUseVersion3 = 0x0004, /*!< Execute macro as a version 3 macro. */
      RKMacroFlagInhibitIfConnected = 0x0008, /*!< Inhibit execution of this macro if a smartphone client is connected. */
      RKMacroFlagEndMarker = 0x0010, /*!< Emit a macro marker with marker id 0 as macro exits. */
      RKMacroFlagStealth = 0x0020, /*!< Macro execution does not reset the sleep timer. */
      RKMacroFlagUnkillable = 0x0040, /*!< This macro can not be aborted. This is only valid for system macros. */
      RKMacroFlagExtendedFlags = 0x0080 /*!< Indicates there are extended flags. */
};

/*!
 * @brief Class that encapsulates a save temporary macro command.
 *
 * This class is used to upload a temporary macro to the device. Macro are sets of commands that 
 * the device runs through instead of sending the individual commands.
 *
 * @sa RKSaveTemporaryMacroResponse
 */
@interface RKSaveTemporaryMacroCommand : RKDeviceCommand

/*! A bitwise OR value of the macro flags.*/
@property ( nonatomic, readonly ) RKMacroFlags macroFlags;
/*! A buffer with the binary representation of the macro. */
@property ( nonatomic, readonly ) NSData *macro;

/*! 
 * @param data The binary representation of the macro.
 * @param flags A set of flags created by bitwise or RKMacroFlags mask values.
 */
+ (instancetype) commandWithMacro:(NSData *) data flags:(RKMacroFlags) flags;

/*! 
 * @param data The binary representation of the macro.
 * @param flags A set of flags created by bitwise or RKMacroFlags mask values.
 * @param delay A time interval in seconds to delay sending the command.
 */
+ (instancetype) commandWithMacro:(NSData *) data flags:(RKMacroFlags) flags delay:(NSTimeInterval) delay;

/*!
 * Initializer to set up the command.
 * @param data The binary representation of the macro.
 * @param flags A set of flags created by bitwise or RKMacroFlags mask values.
 * @return The initialized object.
 */
- (instancetype) initWithMacro:(NSData *) data flags:(RKMacroFlags) flags;

@end
