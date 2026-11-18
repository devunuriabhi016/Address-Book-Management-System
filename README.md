
# Address Book in C

This is a small address book that runs in the terminal. I made it in C while learning embedded systems, mainly to practice structures, pointers, strings and file handling in one real project instead of separate exercises.

You can add contacts, search for them, edit them, delete them, and see them all in a sorted list. Your contacts are saved in a file, so they are still there the next time you run the program.

## What you can do

1. Create a contact (name, phone, email)
2. Search by name, phone number or email
3. Edit any detail of a contact
4. Delete a contact
5. List all contacts, sorted A to Z by name
6. Save and exit
7. Exit without saving

## What it checks while you type

I did not want wrong data going into the book, so the program checks every input:

- **Name:** only letters, spaces and dots
- **Phone:** exactly 10 digits, and the same number cannot be added twice
- **Email:** small letters, numbers, `.` and `@`, only one `@`, and it must end with `.com`. The same email cannot be added twice either.

If something is wrong, it tells you and asks again. If two people have the same name, the search shows both and you pick the right one using the serial number.

The book holds up to 100 contacts. It also stops long inputs from overflowing the memory, so typing a very long name will not crash it.

## How to run it

You need `gcc` installed.

```bash
git clone https://github.com/YOUR_USERNAME/address-book.git
cd address-book
gcc main.c contact.c file.c -o addressbook
./addressbook
```

One thing to remember: your changes are saved only when you choose **6. Save and Exit**. If you choose 7, everything you did in that run is thrown away.

The first time you run it, you will see `null null` on the screen. That is only because the save file does not exist yet. It is created when you save for the first time.

## Files in this project

- `main.c` shows the menu and calls the right function
- `contact.c` has the main work: create, search, edit, delete, list and all the checks
- `contact.h` has the structures and function declarations
- `file.c` and `file.h` save and load the contacts

## How contacts are saved

Everything goes into a plain text file called `contacts.csv`. The first line is how many contacts there are, and after that each contact is on its own line:

```
#2
Asha Rao,9876543210,asha@example.com
Ravi Kumar,9123456780,ravi@example.com
```

## What I learned

- Making a structure and keeping many of them in an array
- Passing pointers to functions
- Working with strings (`strcmp`, `strcpy`, `strlen`)
- Reading and writing files
- Splitting one program into several `.c` and `.h` files
- Bubble sort
- Why input length matters. I first had some buffer overflow bugs, then found and fixed them.

## What I want to improve

- Search is exact and case-sensitive, so "asha" will not find "Asha"
- Only `.com` emails are accepted
- Names cannot have numbers or special characters
- Add a Makefile
- Remove the 100 contact limit using dynamic memory



Your Name
[LinkedIn](https://www.linkedin.com/in/your-profile) | [GitHub](https://github.com/YOUR_USERNAME)
