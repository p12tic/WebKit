/*
 * Copyright (C) 2002 Apple Computer, Inc.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

@class NSArray;
@class NSDictionary;
@class NSString;
@class NSView;

@protocol WebCorePluginInfo <NSObject>

- (NSString *)name;
- (NSString *)filename;
- (NSString *)pluginDescription;
- (NSDictionary *)MIMEToExtensionsDictionary;
- (NSDictionary *)MIMEToDescriptionDictionary;

@end

@protocol WebCoreViewFactory

- (NSView *)viewForPluginWithURL:(NSURL *)url serviceType:(NSString *)serviceType arguments:(NSArray *)arguments baseURL:(NSURL *)baseURL;
- (NSArray *)pluginsInfo; // array of id <WebCorePluginInfo>

- (NSView *)viewForJavaAppletWithFrame:(NSRect)frame baseURL:(NSURL *)URL parameters:(NSDictionary *)parameters;

- (BOOL)runJavaScriptTextInputPanelWithPrompt:(NSString *)prompt defaultText:(NSString *)defaultText returningText:(NSString **)result;

@end

@interface WebCoreViewFactory : NSObject
{
}

+ (WebCoreViewFactory *)sharedFactory;

@end

@interface WebCoreViewFactory (SubclassResponsibility) <WebCoreViewFactory>
@end
