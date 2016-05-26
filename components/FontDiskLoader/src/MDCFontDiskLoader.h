/*
 Copyright 2015-present Google Inc. All Rights Reserved.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import <UIKit/UIKit.h>

/** Register and load a custom font resource. */
@interface MDCFontDiskLoader : NSObject <NSCopying>

#pragma mark Creating a font resource

/**
 Designated initializer for the MDCFontDiskLoader.

 @param fontName The font's name as it is defined in the resource file.
 @param fontURL The url location of the font on the file system.
 */
- (nonnull instancetype)initWithName:(nonnull NSString *)fontName
                                 URL:(nonnull NSURL *)fontURL NS_DESIGNATED_INITIALIZER;

/**
 Convenience initializer for the MDCFontDiskLoader.

 @param fontName The font's name as it is defined in the ttf file.
 @param filename The name of the font file. For example a *.ttf file.
 @param bundleFilename The name of the bundle.
 @param baseBundle The bundle to look in.
 */
- (nonnull instancetype)initWithFontName:(nonnull NSString *)fontName
                                filename:(nonnull NSString *)filename
                          bundleFileName:(nonnull NSString *)bundleFilename
                              baseBundle:(nonnull NSBundle *)baseBundle;

- (nonnull instancetype)init NS_UNAVAILABLE;

#pragma mark Accessing a font's properties

/** The name of the font within the font resource file. */
@property(nonatomic, strong, nonnull) NSString *fontName;

/** The URL of the font asset. */
@property(nonatomic, strong, readonly, nullable) NSURL *fontURL;

#pragma mark Registering a font

/**
 Attempts to register the font.

 The @c isRegistered and @c hasFailedRegistration flags reflect the results of this registration
 attempt. Returns true if the font is registered. If font registration fails, subsequent calls to
 registerFont will fail unless unregisterFont is called first.
 */
- (BOOL)registerFont;

/** Attempts to unregister the font. Returns true when the font is unregistered. */
- (BOOL)unregisterFont;

#pragma mark Accessing the font's registration status

/** The registered state of the custom font. */
@property(nonatomic) BOOL isRegistered;

/** This flag is true when the registration failed. It prevents future attempts at registration. */
@property(nonatomic) BOOL hasFailedRegistration;

#pragma mark Requesting fonts of a given size

/** A convience method for getting a font. */
- (nullable UIFont *)fontOfSize:(CGFloat)fontSize;

@end