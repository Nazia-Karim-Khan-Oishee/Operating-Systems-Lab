#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Please provide the correct input in the below format."
    echo "Usage: ./validate_emails.sh <list of email addresses>"
    exit 1
fi

valid_emails=()
invalid_emails=()


for email in "$@"; do
if [[ $email =~ ^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$ ]]; then
valid_emails+=("$email")
else
invalid_emails+=("$email")
fi
done

echo "Valid emails: ${valid_emails[*]}"
echo "Invalid emails: ${invalid_emails[*]}"

