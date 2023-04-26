
def store_transactions(transaction_id, transactions):
    """
    :param transaction_id:
    :param transactions: transactions_even
    :return: transactions
    """

    if transactions % 2 == 0:
        transaction_id = transactions
        print(transaction_id)

    # Write code that stores the transaction_id if it is an even number
    # The function should return the transactions


for i in range(10):
    store_transactions(i,i)

