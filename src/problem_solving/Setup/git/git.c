# Set up your username and email
git config --global user.name "YourGitHubUsername"
git config --global user.email "youremail@example.com"

# Generate SSH key
ssh-keygen -t rsa -b 4096 -C "youremail@example.com"

# Add SSH key to GitHub (copy the key to clipboard)
cat ~/.ssh/id_rsa.pub

# Clone the repository
cd path/to/your/folder
git clone git@github.com:YourGitHubUsername/repository-name.git  # SSH
# OR
git clone https://github.com/YourGitHubUsername/repository-name.git  # HTTPS

# Make changes
cd repository-name
# Edit files...

# Commit and push changes
git add .
git commit -m "Your commit message"
git push origin main
