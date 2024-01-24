Node* deleteLast(Node* list) {
    // Check if the list is empty or has only one node
    if (list == nullptr || list->next == nullptr) {
        delete list;  // Delete the only node or nullptr
        return nullptr;  // Return nullptr to indicate an empty list
    }

    // Traverse the list to find the second-to-last node
    Node* current = list;
    while (current->next->next != nullptr) {
        current = current->next;
    }

    // Delete the last node and update the next pointer of the second-to-last node
    delete current->next;
    current->next = nullptr;

    return list;  // Return the updated head of the list
}
