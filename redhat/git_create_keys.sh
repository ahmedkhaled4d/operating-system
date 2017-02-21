!/bin/sh
        #git_create_keys.sh
        #Created by Ian Shaw
echo "Input your OAuth token now:"
read TOKEN
PUBKEY=$(cat ~/.ssh/id_rsa.pub)

RESPONSE=`curl -s -H "Authorization: token ${TOKEN}" \
  -X POST --data-binary "{\"title\":\"best@email\",\"key\":\"${PUBKEY}\"}" \
  https://api.github.com/user/keys`

echo -ne '\n' | ssh-keygen -t rsa -b 4096
eval $(ssh-agent -s)
ssh-add ~/.ssh/id_rsa
echo "Done! - Verifying"
ssh git@github.com
