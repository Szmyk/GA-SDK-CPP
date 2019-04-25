//
// GA-SDK-CPP
// Copyright 2018 GameAnalytics C++ SDK. All rights reserved.
//

#pragma once

#include <vector>
#include <string>
#include "rapidjson/document.h"
#include "GameAnalytics.h"
#include "GAHTTPApi.h"

namespace gameanalytics
{
    namespace validators
    {
        class GAValidator
        {
         public:
            // ---------- EVENTS -------------- //

            // user created events
            static bool validateBusinessEvent(
                const char* currency,
                long amount,
                const char* cartType,
                const char* itemType,
                const char* itemId
                );

            static bool validateResourceEvent(
                EGAResourceFlowType flowType,
                const char* currency,
                double amount,
                const char* itemType,
                const char* itemId
                );


            static bool validateProgressionEvent(
                EGAProgressionStatus progressionStatus,
                const char* progression01,
                const char* progression02,
                const char* progression03
                );

            static bool validateDesignEvent(
                const char* eventId,
                double value
                );

            static bool validateErrorEvent(
                EGAErrorSeverity severity,
                const std::string& message
                );

            static bool validateSdkErrorEvent(const char* gameKey, const char* gameSecret, http::EGASdkErrorType type);


            // -------------------- HELPERS --------------------- //

            // event params
            static bool validateKeys(const char* gameKey, const char* gameSecret);
            static bool validateCurrency(const char* currency);
            static bool validateEventPartLength(const char* eventPart, bool allowNull);
            static bool validateEventPartCharacters(const char* eventPart);
            static bool validateEventIdLength(const char* eventId);
            static bool validateEventIdCharacters(const char* eventId);
            static bool validateShortString(const std::string& shortString, bool canBeEmpty);
            static bool validateString(const std::string& string, bool canBeEmpty);
            static bool validateLongString(const std::string& longString, bool canBeEmpty);

            // validate wrapper version, build, engine version, store
            static bool validateSdkWrapperVersion(const std::string& wrapperVersion);
            static bool validateBuild(const std::string& build);
            static bool validateEngineVersion(const std::string& engineVersion);
            static bool validateStore(const std::string& store);
            static bool validateConnectionType(const std::string& connectionType);

            // dimensions
            static bool validateCustomDimensions(const StringVector& customDimensions);

            // resource
            static bool validateResourceCurrencies(const StringVector& resourceCurrencies);
            static bool validateResourceItemTypes(const StringVector& resourceItemTypes);

            //static  bool validateCustomDimensionsWithDimension01:const std::string& dimension01 andDimension02:const std::string& dimension02 andDimension03:const std::string& dimension03 andEventTag:const std::string& eventTag;
            static bool validateDimension01(const std::string& dimension01);
            static bool validateDimension02(const std::string& dimension02);
            static bool validateDimension03(const std::string& dimension03);

            static void validateAndCleanInitRequestResponse(const rapidjson::Value& initResponse, rapidjson::Document& out);

            // array of strings
            static bool validateArrayOfStrings(
                const StringVector& arrayOfStrings,
                unsigned long maxCount,
                unsigned long maxStringLength,
                bool allowNoValues,
                const std::string& arrayTag
                );
            // facebook id, gender, birthyear
            static bool validateFacebookId(const std::string& facebookId);
            static bool validateGender(EGAGender gender);
            static bool validateBirthyear(int64_t birthYear);
            static bool validateClientTs(int64_t clientTs);

            static bool validateUserId(const std::string& uId);
        };
    }
}
