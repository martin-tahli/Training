from datetime import datetime


def _get_request_json_data(date=None, receipt_id=None, seconds=86400, timespan=None):
    today = datetime.today()
    json_data = {
        "deliverydate": str(date or today),
        "minutes": seconds,
    }
    if timespan:
        json_data["timespan"] = timespan
    if receipt_id:
        json_data["receipt_ids"] = [{"receiptId": str(receipt_id)}]
    return json_data


json_data = _get_request_json_data(11)
json_data_two = _get_request_json_data("2023-01-10", 11)
json_data_three = _get_request_json_data("2023-01-10", 8391028312983, 11)

print(json_data)
print(json_data_two)
print(json_data_three)
