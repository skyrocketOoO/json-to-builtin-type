#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include "json_utils.hpp"

using namespace redfish::json_util::details;

TEST(ParseValueHelperTest, ParseUint8) {
    nlohmann::json jsonValue = 42;
    uint8_t value = 0;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value, static_cast<uint8_t>(42));
}

TEST(ParseValueHelperTest, ParseUint16) {
    nlohmann::json jsonValue = 12345;
    uint16_t value = 0;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value, static_cast<uint16_t>(12345));
}

TEST(ParseValueHelperTest, ParseInt16) {
    nlohmann::json jsonValue = -12345;
    int16_t value = 0;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value, static_cast<int16_t>(-12345));
}

TEST(ParseValueHelperTest, ParseUint32) {
    nlohmann::json jsonValue = 1234567890;
    uint32_t value = 0;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value, static_cast<uint32_t>(1234567890));
}

TEST(ParseValueHelperTest, ParseInt32) {
    nlohmann::json jsonValue = -123456789;
    int32_t value = 0;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value, static_cast<int32_t>(-123456789));
}

TEST(ParseValueHelperTest, ParseUint64) {
    nlohmann::json jsonValue = 12345678901234567890ULL;
    uint64_t value = 0;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value, static_cast<uint64_t>(12345678901234567890ULL));
}

TEST(ParseValueHelperTest, ParseInt64) {
    nlohmann::json jsonValue = -1234567890123456789LL;
    int64_t value = 0;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value, static_cast<int64_t>(-1234567890123456789LL));
}

TEST(ParseValueHelperTest, ParseBool) {
    nlohmann::json jsonValue = true;
    bool value = false;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value, true);
}

TEST(ParseValueHelperTest, ParseDouble) {
    nlohmann::json jsonValue = 42.42;
    double value = 0.0;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value, 42.42);
}

TEST(ParseValueHelperTest, ParseString) {
    nlohmann::json jsonValue = "hello world";
    std::string value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value, "hello world");
}

TEST(ParseValueHelperTest, ParseJsonObject) {
    nlohmann::json jsonValue = {{"key1", 1}, {"key2", "value"}};
    nlohmann::json::object_t value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value["key1"], 1);
    EXPECT_EQ(value["key2"], "value");
}

TEST(ParseValueHelperTest, ParseVariantStringNullptr) {
    nlohmann::json jsonValue = "test";
    std::variant<std::string, std::nullptr_t> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(std::get<std::string>(value), "test");
}

TEST(ParseValueHelperTest, ParseVariantUint8Nullptr) {
    nlohmann::json jsonValue = 42;
    std::variant<uint8_t, std::nullptr_t> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(std::get<uint8_t>(value), static_cast<uint8_t>(42));
}

TEST(ParseValueHelperTest, ParseVariantInt16Nullptr) {
    nlohmann::json jsonValue = -12345;
    std::variant<int16_t, std::nullptr_t> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(std::get<int16_t>(value), static_cast<int16_t>(-12345));
}

TEST(ParseValueHelperTest, ParseVariantUint16Nullptr) {
    nlohmann::json jsonValue = 12345;
    std::variant<uint16_t, std::nullptr_t> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(std::get<uint16_t>(value), static_cast<uint16_t>(12345));
}

TEST(ParseValueHelperTest, ParseVariantInt32Nullptr) {
    nlohmann::json jsonValue = -123456;
    std::variant<int32_t, std::nullptr_t> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(std::get<int32_t>(value), static_cast<int32_t>(-123456));
}

TEST(ParseValueHelperTest, ParseVariantUint32Nullptr) {
    nlohmann::json jsonValue = 123456;
    std::variant<uint32_t, std::nullptr_t> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(std::get<uint32_t>(value), static_cast<uint32_t>(123456));
}

TEST(ParseValueHelperTest, ParseVariantInt64Nullptr) {
    nlohmann::json jsonValue = -1234567890123;
    std::variant<int64_t, std::nullptr_t> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(std::get<int64_t>(value), static_cast<int64_t>(-1234567890123));
}

TEST(ParseValueHelperTest, ParseVariantUint64Nullptr) {
    nlohmann::json jsonValue = 1234567890123;
    std::variant<uint64_t, std::nullptr_t> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(std::get<uint64_t>(value), static_cast<uint64_t>(1234567890123));
}

TEST(ParseValueHelperTest, ParseVariantDoubleNullptr) {
    nlohmann::json jsonValue = 42.42;
    std::variant<double, std::nullptr_t> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(std::get<double>(value), 42.42);
}

TEST(ParseValueHelperTest, ParseVariantBoolNullptr) {
    nlohmann::json jsonValue = true;
    std::variant<bool, std::nullptr_t> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(std::get<bool>(value), true);
}

TEST(ParseValueHelperTest, ParseVectorUint8) {
    nlohmann::json jsonValue = {1, 2, 3, 4};
    std::vector<uint8_t> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value, std::vector<uint8_t>({1, 2, 3, 4}));
}

TEST(ParseValueHelperTest, ParseVectorUint16) {
    nlohmann::json jsonValue = {100, 200, 300};
    std::vector<uint16_t> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value, std::vector<uint16_t>({100, 200, 300}));
}

TEST(ParseValueHelperTest, ParseVectorInt16) {
    nlohmann::json jsonValue = {-100, -200, -300};
    std::vector<int16_t> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value, std::vector<int16_t>({-100, -200, -300}));
}

TEST(ParseValueHelperTest, ParseVectorUint32) {
    nlohmann::json jsonValue = {100000, 200000, 300000};
    std::vector<uint32_t> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value, std::vector<uint32_t>({100000, 200000, 300000}));
}

TEST(ParseValueHelperTest, ParseVectorInt32) {
    nlohmann::json jsonValue = {-100000, -200000, -300000};
    std::vector<int32_t> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value, std::vector<int32_t>({-100000, -200000, -300000}));
}

TEST(ParseValueHelperTest, ParseVectorUint64) {
    nlohmann::json jsonValue = {100000000000ULL, 200000000000ULL};
    std::vector<uint64_t> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value, std::vector<uint64_t>({100000000000ULL, 200000000000ULL}));
}

TEST(ParseValueHelperTest, ParseVectorInt64) {
    nlohmann::json jsonValue = {-100000000000LL, -200000000000LL};
    std::vector<int64_t> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value, std::vector<int64_t>({-100000000000LL, -200000000000LL}));
}

TEST(ParseValueHelperTest, ParseVectorDouble) {
    nlohmann::json jsonValue = {1.1, 2.2, 3.3};
    std::vector<double> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value, std::vector<double>({1.1, 2.2, 3.3}));
}

TEST(ParseValueHelperTest, ParseVectorString) {
    nlohmann::json jsonValue = {"one", "two", "three"};
    std::vector<std::string> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value, std::vector<std::string>({"one", "two", "three"}));
}

TEST(ParseValueHelperTest, ParseVectorJsonObject) {
    nlohmann::json jsonValue = {{{"key1", 1}, {"key2", "value"}},
                                {{"keyA", "A"}, {"keyB", "B"}}};
    std::vector<nlohmann::json::object_t> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value[0]["key1"], 1);
    EXPECT_EQ(value[0]["key2"], "value");
    EXPECT_EQ(value[1]["keyA"], "A");
    EXPECT_EQ(value[1]["keyB"], "B");
}

TEST(ParseValueHelperTest, ParseOptionalUint8) {
    nlohmann::json jsonValue = 42;
    std::optional<uint8_t> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value, std::optional<uint8_t>(42));
}

TEST(ParseValueHelperTest, ParseOptionalDouble) {
    nlohmann::json jsonValue = 3.14;
    std::optional<double> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value, std::optional<double>(3.14));
}

TEST(ParseValueHelperTest, ParseOptionalString) {
    nlohmann::json jsonValue = "optional string";
    std::optional<std::string> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value, std::optional<std::string>("optional string"));
}

TEST(ParseValueHelperTest, ParseOptionalJsonObject) {
    nlohmann::json jsonValue = {{"key1", "value1"}, {"key2", 2}};
    std::optional<nlohmann::json::object_t> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    ASSERT_TRUE(value.has_value());
    EXPECT_EQ((*value)["key1"], "value1");
    EXPECT_EQ((*value)["key2"], 2);
}

TEST(ParseValueHelperTest, ParseOptionalVectorUint8) {
    nlohmann::json jsonValue = {1, 2, 3};
    std::optional<std::vector<uint8_t>> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value, std::optional<std::vector<uint8_t>>({1, 2, 3}));
}

TEST(ParseValueHelperTest, ParseOptionalVectorInt64) {
    nlohmann::json jsonValue = {-100000000000LL, -200000000000LL};
    std::optional<std::vector<int64_t>> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value, std::optional<std::vector<int64_t>>({-100000000000LL, -200000000000LL}));
}

TEST(ParseValueHelperTest, ParseOptionalVectorDouble) {
    nlohmann::json jsonValue = {1.1, 2.2, 3.3};
    std::optional<std::vector<double>> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value, std::optional<std::vector<double>>({1.1, 2.2, 3.3}));
}

TEST(ParseValueHelperTest, ParseOptionalVectorString) {
    nlohmann::json jsonValue = {"one", "two", "three"};
    std::optional<std::vector<std::string>> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    EXPECT_EQ(value, std::optional<std::vector<std::string>>({"one", "two", "three"}));
}

TEST(ParseValueHelperTest, ParseOptionalVectorJsonObject) {
    nlohmann::json jsonValue = {{{"key1", 1}, {"key2", "value"}},
                                {{"keyA", "A"}, {"keyB", "B"}}};
    std::optional<std::vector<nlohmann::json::object_t>> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    ASSERT_TRUE(value.has_value());
    EXPECT_EQ((*value)[0]["key1"], 1);
    EXPECT_EQ((*value)[0]["key2"], "value");
    EXPECT_EQ((*value)[1]["keyA"], "A");
    EXPECT_EQ((*value)[1]["keyB"], "B");
}

TEST(ParseValueHelperTest, ParseOptionalVariantStringNullptr) {
    nlohmann::json jsonValue = "variant string";
    std::optional<std::variant<std::string, std::nullptr_t>> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    ASSERT_TRUE(value.has_value());
    EXPECT_EQ(std::get<std::string>(*value), "variant string");
}

TEST(ParseValueHelperTest, ParseOptionalVariantUint8Nullptr) {
    nlohmann::json jsonValue = 255;
    std::optional<std::variant<uint8_t, std::nullptr_t>> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    ASSERT_TRUE(value.has_value());
    EXPECT_EQ(std::get<uint8_t>(*value), 255);
}

TEST(ParseValueHelperTest, ParseOptionalVariantInt16Nullptr) {
    nlohmann::json jsonValue = -32768;
    std::optional<std::variant<int16_t, std::nullptr_t>> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    ASSERT_TRUE(value.has_value());
    EXPECT_EQ(std::get<int16_t>(*value), -32768);
}

TEST(ParseValueHelperTest, ParseOptionalVariantUint16Nullptr) {
    nlohmann::json jsonValue = 65535;
    std::optional<std::variant<uint16_t, std::nullptr_t>> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    ASSERT_TRUE(value.has_value());
    EXPECT_EQ(std::get<uint16_t>(*value), 65535);
}

TEST(ParseValueHelperTest, ParseOptionalVariantInt32Nullptr) {
    nlohmann::json jsonValue = -2147483648;
    std::optional<std::variant<int32_t, std::nullptr_t>> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    ASSERT_TRUE(value.has_value());
    EXPECT_EQ(std::get<int32_t>(*value), -2147483648);
}

TEST(ParseValueHelperTest, ParseOptionalVariantUint32Nullptr) {
    nlohmann::json jsonValue = 4294967295;
    std::optional<std::variant<uint32_t, std::nullptr_t>> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    ASSERT_TRUE(value.has_value());
    EXPECT_EQ(std::get<uint32_t>(*value), 4294967295);
}

TEST(ParseValueHelperTest, ParseOptionalVariantInt64Nullptr) {
    nlohmann::json jsonValue = -9223372036854775807LL;
    std::optional<std::variant<int64_t, std::nullptr_t>> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    ASSERT_TRUE(value.has_value());
    EXPECT_EQ(std::get<int64_t>(*value), -9223372036854775807LL);
}

TEST(ParseValueHelperTest, ParseOptionalVariantUint64Nullptr) {
    nlohmann::json jsonValue = 18446744073709551615ULL;
    std::optional<std::variant<uint64_t, std::nullptr_t>> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    ASSERT_TRUE(value.has_value());
    EXPECT_EQ(std::get<uint64_t>(*value), 18446744073709551615ULL);
}

TEST(ParseValueHelperTest, ParseOptionalVariantNullptr) {
    nlohmann::json jsonValue = nullptr;
    std::optional<std::variant<int32_t, std::nullptr_t>> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    ASSERT_TRUE(value.has_value());
    EXPECT_EQ(std::get<std::nullptr_t>(*value), nullptr);
}

TEST(ParseValueHelperTest, ParseOptionalVariantDoubleNullptr) {
    nlohmann::json jsonValue = 3.14159;
    std::optional<std::variant<double, std::nullptr_t>> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    ASSERT_TRUE(value.has_value());
    EXPECT_EQ(std::get<double>(*value), 3.14159);
}

TEST(ParseValueHelperTest, ParseOptionalVariantBoolNullptr) {
    nlohmann::json jsonValue = true;
    std::optional<std::variant<bool, std::nullptr_t>> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    ASSERT_TRUE(value.has_value());
    EXPECT_EQ(std::get<bool>(*value), true);
}

TEST(ParseValueHelperTest, ParseOptionalVectorVariantObjectOrNullptr) {
    nlohmann::json jsonValue = {{{"key1", 42}}, nullptr, {{"key2", "value"}}};
    std::optional<std::vector<std::variant<nlohmann::json::object_t, std::nullptr_t>>> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    ASSERT_TRUE(value.has_value());
    EXPECT_TRUE(std::holds_alternative<nlohmann::json::object_t>((*value)[0]));
    EXPECT_TRUE(std::holds_alternative<std::nullptr_t>((*value)[1]));
    EXPECT_TRUE(std::holds_alternative<nlohmann::json::object_t>((*value)[2]));
    EXPECT_EQ(std::get<nlohmann::json::object_t>((*value)[0])["key1"], 42);
}

TEST(ParseValueHelperTest, ParseOptionalVectorVariantStringObjectOrNullptr) {
    nlohmann::json jsonValue = {"string", nullptr, {{"key", "value"}}};
    std::optional<std::vector<std::variant<std::string, nlohmann::json::object_t, std::nullptr_t>>> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    ASSERT_TRUE(value.has_value());
    EXPECT_TRUE(std::holds_alternative<std::string>((*value)[0]));
    EXPECT_TRUE(std::holds_alternative<std::nullptr_t>((*value)[1]));
    EXPECT_TRUE(std::holds_alternative<nlohmann::json::object_t>((*value)[2]));
    EXPECT_EQ(std::get<std::string>((*value)[0]), "string");
    EXPECT_EQ(std::get<nlohmann::json::object_t>((*value)[2])["key"], "value");
}

TEST(ParseValueHelperTest, ParseOptionalComplexVariant) {
    nlohmann::json jsonValue = {{"key", "value"}};
    std::optional<std::variant<
        std::string, int, bool, double,
        nlohmann::json::object_t,
        std::vector<int>,
        std::vector<std::string>,
        std::vector<bool>,
        std::vector<double>
    >> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    ASSERT_TRUE(value.has_value());
    EXPECT_TRUE(std::holds_alternative<nlohmann::json::object_t>(*value));
    EXPECT_EQ(std::get<nlohmann::json::object_t>(*value)["key"], "value");
}

TEST(ParseValueHelperTest, ParseOptionalComplexVariantVectorInt) {
    nlohmann::json jsonValue = {1, 2, 3};
    std::optional<std::variant<
        std::string, int, bool, double,
        nlohmann::json::object_t,
        std::vector<int>,
        std::vector<std::string>,
        std::vector<bool>,
        std::vector<double>
    >> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    ASSERT_TRUE(value.has_value());
    EXPECT_TRUE(std::holds_alternative<std::vector<int>>(*value));
    EXPECT_EQ(std::get<std::vector<int>>(*value), std::vector<int>({1, 2, 3}));
}

TEST(ParseValueHelperTest, ParseJson) {
    nlohmann::json jsonValue = {{"key", 42}};
    nlohmann::json value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    ASSERT_NE(value, nullptr);  // Ensure the value is not null

    nlohmann::json expectedValue = {{"key", 42}};
    EXPECT_EQ(value, expectedValue);  // Compare value to the expected JSON
}

TEST(ParseValueHelperTest, ParseOptionalVectorJson) {
    nlohmann::json jsonValue = {{1}, {{"key", "value"}}};
    std::optional<std::vector<nlohmann::json>> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    ASSERT_TRUE(value.has_value());

    ASSERT_NE(*value, nullptr);
    ASSERT_TRUE((*value)[1].is_object());
    nlohmann::json expectedValue = {{"key", "value"}};
    EXPECT_EQ((*value)[1], expectedValue);
}

TEST(ParseValueHelperTest, ParseVectorJson) {
    nlohmann::json jsonValue = {{1}, {"string"}, {{"key", "value"}}};
    std::vector<nlohmann::json> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    ASSERT_TRUE((value)[2].is_object());
    nlohmann::json expectedValue = {{"key", "value"}};
    EXPECT_EQ((value)[2], expectedValue);
}

TEST(ParseValueHelperTest, ParseOptionalJson) {
    nlohmann::json jsonValue = {{"key", "value"}};
    std::optional<nlohmann::json> value;
    EXPECT_EQ(parseValueHelper(jsonValue, "field key", value), UnpackErrorCode::success);
    ASSERT_TRUE(value.has_value());
    ASSERT_TRUE((*value).is_object());
    EXPECT_EQ((*value)["key"], "value");
}
